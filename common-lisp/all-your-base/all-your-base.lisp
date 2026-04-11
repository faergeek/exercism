(defpackage :all-your-base
  (:use :cl)
  (:export :rebase))

(in-package :all-your-base)

(defun rebase (list-digits in-base out-base)
  (if (and (> in-base 1) (> out-base 1))
    (let ((n (let ((pos (list-length list-digits)))
               (reduce
                 (lambda (a x)
                   (if (or (< x 0) (>= x in-base))
                     (return-from rebase nil))
                   (decf pos)
                   (+ a (* x (expt in-base pos))))
                 list-digits
                 :initial-value 0))))
      (if (= n 0) '(0)
        (let ((result nil))
          (loop until (= n 0)
                do (progn
                     (setq result (cons (rem n out-base) result))
                     (setq n (floor (/ n out-base))))
                finally (return result)))))))
