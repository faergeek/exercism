use std::fmt::Display;

#[derive(Debug, PartialEq)]
pub struct Clock {
    hours: u8,
    minutes: u8,
}

impl Display for Clock {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.write_fmt(format_args!("{:0>#2}:{:0>#2}", self.hours, self.minutes))
    }
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let mut h = hours;
        let mut m = minutes;

        while m < 0 {
            m += 60;
            h -= 1;
        }

        while h < 0 {
            h += 24;
        }

        Self {
            hours: ((h + m / 60) % 24) as u8,
            minutes: (m % 60) as u8,
        }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        Self::new(self.hours as i32, self.minutes as i32 + minutes)
    }
}
