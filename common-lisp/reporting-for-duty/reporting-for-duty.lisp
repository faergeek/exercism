(defpackage :reporting-for-duty
  (:use :cl)
  (:export :format-quarter-value :format-two-quarters
           :format-two-quarters-for-reading))

(in-package :reporting-for-duty)

(defun format-quarter-value (quarter value)
  (format nil "The value ~a quarter: ~a" quarter value))

(defun format-two-quarters (stream first-quarter first-value second-quarter second-value)
  (format stream "~%~a~%~a~%"
          (format-quarter-value first-quarter first-value)
          (format-quarter-value second-quarter second-value)))

(defun format-two-quarters-for-reading (stream first-quarter first-value second-quarter second-value)
  (format stream "~s"
          (list (format-quarter-value first-quarter first-value)
                (format-quarter-value second-quarter second-value))))
