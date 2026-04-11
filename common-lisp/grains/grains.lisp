(defpackage :grains
  (:use :cl)
  (:export :square :total))
(in-package :grains)

(defun square (n) (ash 1 (- n 1)))

(defun total () (- (square 65) 1))
