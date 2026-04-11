(defpackage :lillys-lasagna
  (:use :cl)
  (:export :expected-time-in-oven
           :remaining-minutes-in-oven
           :preparation-time-in-minutes
           :elapsed-time-in-minutes))

(in-package :lillys-lasagna)

(defun expected-time-in-oven ()
  "Returns expected time in oven"
  337)

(defun remaining-minutes-in-oven (elapsed-minutes)
  "Returns remaining minutes in oven, given ELAPSED-MINUTES"
  (- (expected-time-in-oven) elapsed-minutes))

(defun preparation-time-in-minutes (layers)
  "Returns preparation time in minutes for the given LAYERS"
  (* layers 19))

(defun elapsed-time-in-minutes (layers elapsed-minutes)
  "Returns elapsed time in minutes given LAYERS and ELAPSED-MINUTES"
  (+ (preparation-time-in-minutes layers) elapsed-minutes))
