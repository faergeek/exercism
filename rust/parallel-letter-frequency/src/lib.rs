use std::{collections::HashMap, str::FromStr, sync::mpsc, thread};

struct Worker {
    in_tx: mpsc::Sender<String>,
    handle: thread::JoinHandle<()>,
}

pub fn frequency(input: &[&str], worker_count: usize) -> HashMap<char, usize> {
    if worker_count == 0 {
        panic!("worker_count can't be 0");
    }

    let (out_tx, out_rx) = mpsc::channel();

    let mut workers = Vec::new();
    for _ in 0..worker_count {
        let out_tx = out_tx.clone();
        let (in_tx, in_rx) = mpsc::channel();

        workers.push(Worker {
            in_tx,
            handle: thread::spawn(move || {
                for item in in_rx {
                    let mut freqs = HashMap::<char, usize>::new();

                    for ch in item.to_lowercase().chars().filter(|c| c.is_alphabetic()) {
                        freqs.insert(ch, freqs.get(&ch).unwrap_or(&(0 as usize)) + 1);
                    }

                    out_tx.send(freqs).unwrap();
                }
            }),
        });
    }
    drop(out_tx);

    let mut worker_index = 0;
    for item in input {
        let worker = &workers[worker_index];
        worker_index = (worker_index + 1) % workers.len();

        let str = String::from_str(item).unwrap();
        worker.in_tx.send(str).unwrap();
    }

    for worker in workers {
        drop(worker.in_tx);
        worker.handle.join().unwrap();
    }

    let mut freqs = HashMap::new();
    for freq in out_rx {
        for (k, v) in freq {
            freqs.insert(k, freqs.get(&k).unwrap_or(&(0 as usize)) + v);
        }
    }

    freqs
}
