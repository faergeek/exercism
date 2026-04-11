(defpackage :larrys-winning-checker
  (:use :cl)
  (:export
   :make-empty-board
   :make-board-from-list
   :all-the-same-p
   :row
   :column))

(in-package :larrys-winning-checker)

(defun make-empty-board ()
  (make-array '(3 3) :initial-element nil))

(defun make-board-from-list (list)
  (loop with result = (make-empty-board)
        for i from 0 to (1- (array-dimension result 0))
        for rows = list then (cdr rows)
        for row = (car rows)
        do (loop for j from 0 to (1- (array-dimension result 1))
                for els = row then (cdr els)
                for el = (car els)
                do (setf (aref result i j) el))
        finally (return result)))

(defun all-the-same-p (row-or-col)
  (and (eq (aref row-or-col 0) (aref row-or-col 1))
       (eq (aref row-or-col 1) (aref row-or-col 2))))

(defun row (board row-num)
  (loop with result = (make-array '(3) :initial-element nil)
        for i from 0 to (1- (array-dimension board 0))
        do (setf (aref result i) (aref board row-num i))
        finally (return result)))

(defun column (board col-num)
  (loop with result = (make-array '(3) :initial-element nil)
        for i from 0 to (1- (array-dimension board 1))
        do (setf (aref result i) (aref board i col-num))
        finally (return result)))
