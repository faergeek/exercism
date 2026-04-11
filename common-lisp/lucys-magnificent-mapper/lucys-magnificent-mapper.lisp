(defpackage :lucys-magnificent-mapper
  (:use :cl)
  (:export :make-magnificent-maybe :only-the-best))

(in-package :lucys-magnificent-mapper)

(defun make-magnificent-maybe (fn seq)
  (mapcar fn seq))

(defun only-the-best (fn seq)
  (remove-if fn (remove 1 seq)))
