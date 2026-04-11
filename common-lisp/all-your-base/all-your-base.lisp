(defpackage :all-your-base
  (:use :cl)
  (:export :rebase))

(in-package :all-your-base)

(defun from-base (list-digits base)
  (if (> base 1)
    (let ((pos (list-length list-digits)))
      (reduce
        (lambda (a x)
          (if (and a (>= x 0) (< x base))
            (progn
              (decf pos)
              (+ a (* x (expt base pos))))))
        list-digits
        :initial-value 0))))

(defun to-base (n base)
  (if (and n (> base 1))
    (if (= n 0)
      '(0)
      (reverse (loop until (= n 0)
                     collect (rem n base)
                     do (setq n (floor (/ n base))))))))

(defun rebase (list-digits in-base out-base)
  (to-base
    (from-base list-digits in-base)
    out-base))
