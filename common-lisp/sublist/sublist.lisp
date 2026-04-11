(defpackage :sublist
  (:use :cl)
  (:export :sublist))

(in-package :sublist)

(defun elements-are-equal (a b)
  (or (null a) (null b)
      (loop for x in a
            for y in b
            for r = (= x y) then (= x y)
            while r
            finally (return r))))

(defun is-equal (a b)
  (let ((a-len (length a))
        (b-len (length b)))
    (when (= a-len b-len)
      (elements-are-equal a b))))

(defun is-superlist (a b)
  (let ((a-len (length a))
        (b-len (length b)))
    (when (> a-len b-len)
      (loop for i from 0 to (- a-len b-len)
            for a-tail = a then (cdr a-tail)
            for r = (elements-are-equal a-tail b)
            while (not r)
            finally (return r)))))

(defun sublist (a b)
  (cond
    ((is-equal a b) :equal)
    ((is-superlist a b) :superlist)
    ((is-superlist b a) :sublist)
    (t :unequal)))
