(defpackage :leap
  (:use :cl)
  (:export :leap-year-p))
(in-package :leap)

(defun evenly-divisible (by n)
  (= (mod n by) 0))

(defun leap-year-p (year)
  (and
    (evenly-divisible 4 year)
    (or
      (not (evenly-divisible 100 year))
      (evenly-divisible 400 year))))
