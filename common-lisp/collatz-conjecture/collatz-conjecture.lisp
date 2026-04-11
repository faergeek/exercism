(defpackage :collatz-conjecture
  (:use :cl)
  (:export :collatz))

(in-package :collatz-conjecture)

(defun collatz-step (i n)
  (if (= n 1) i
    (collatz-step (+ i 1)
                  (if (= (mod n 2) 0)
                    (/ n 2)
                    (+ (* n 3) 1)))))

(defun collatz (n)
  (if (< n 1)
    nil
    (collatz-step 0 n)))

(collatz 12)
