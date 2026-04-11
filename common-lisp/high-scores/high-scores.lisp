(defpackage :high-scores
  (:use :cl)
  (:export :make-high-scores-table :add-player
           :set-score :get-score :remove-player))

(in-package :high-scores)

(defun make-high-scores-table ()
  (make-hash-table))

(let ((test-ht (make-hash-table)))
  (setf (gethash :foo test-ht) :bar)
  (gethash :foo test-ht))

(defun add-player (ht k)
  (set-score ht k 0))

(defun set-score (ht k v)
  (setf (gethash k ht) v))

(defun get-score (ht k)
  (or (gethash k ht) 0))

(defun remove-player (ht k)
  (remhash k ht))
