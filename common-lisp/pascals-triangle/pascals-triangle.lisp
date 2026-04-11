(defpackage :pascals-triangle
  (:use :cl)
  (:export :rows))
(in-package :pascals-triangle)

(defun rows (n)
  (defun calc-next-row (prev-row &optional (k-1 0))
    (let ((head (car prev-row)))
      (if head
        (cons
          (+ k-1 head)
          (calc-next-row (cdr prev-row) head)) 
        '(1))))

  (let ((prev-row nil))
    (loop for i from 1 to n
          do (setf prev-row (calc-next-row prev-row))
          collect prev-row)))
