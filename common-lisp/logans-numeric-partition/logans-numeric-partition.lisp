(defpackage :logans-numeric-partition
  (:use :cl)
  (:export :categorize-number :partition-numbers))

(in-package :logans-numeric-partition)

(defun categorize-number (pair n)
  (let ((odds (car pair))
        (evens (cdr pair)))
    (if (evenp n)
      (setf evens (cons n evens))
      (setf odds (cons n odds)))
    (cons odds evens)))

(defun partition-numbers (numbers)
  (reduce #'categorize-number numbers :initial-value '(nil)))
