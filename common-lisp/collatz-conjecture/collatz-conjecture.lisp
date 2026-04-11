(defpackage :collatz-conjecture
  (:use :cl)
  (:export :collatz))

(in-package :collatz-conjecture)

(defun collatz (n)
  (if (> n 0)
    (loop while (> n 1) counting t
          do (setq n (if (evenp n)
                       (/ n 2)
                       (+ (* n 3) 1))))))
