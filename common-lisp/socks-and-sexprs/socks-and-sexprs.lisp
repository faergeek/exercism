(defpackage :socks-and-sexprs
  (:use :cl)
  (:export :lennys-favorite-food :lennys-secret-keyword
           :is-an-atom-p :is-a-cons-p :first-thing :rest-of-it))

(in-package :socks-and-sexprs)

;; Evaluates to some symbol (not a keyword)
(defun lennys-favorite-food () 'lasagna)

;; Evaluates to some keyword
(defun lennys-secret-keyword () :aliens-are-real)
  ;; put your keyword here

;; Evaluates to T if THING is an atom, NIL otherwise
(defun is-an-atom-p (thing) (not (consp thing)))
  ;; put the code to determine if THING is an atom here

;; Evaluates to T if THING is a cons, NIL otherwise
(defun is-a-cons-p (thing) (consp thing))
  ;; put the code to determine if THING is a CONS here

;; Evaluates to the first part of CONS
(defun first-thing (cons) (car cons))
  ;; put the code to get the first part of CONS here

;; Evaluates to the 'rest' of the CONS
(defun rest-of-it (cons) (cdr cons))
  ;; put the code to get the rest of CONS here
