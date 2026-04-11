(defpackage :lillys-lasagna-leftovers
  (:use :cl)
  (:export
   :preparation-time
   :remaining-minutes-in-oven
   :split-leftovers))

(in-package :lillys-lasagna-leftovers)

(defun preparation-time (&rest layers-list)
  (* 19 (length layers-list)))

(defun remaining-minutes-in-oven (&optional (time :normal))
  (case time
    (:very-short 137)
    (:shorter 237)
    (:normal 337)
    (:longer 437)
    (:very-long 537)
    ('nil 0)))

(defun split-leftovers (&key (weight nil weight-supplied-p) (alien 10) (human 10))
  (if weight
   (- weight (+ alien human))
   (if weight-supplied-p
     :looks-like-someone-was-hungry
     :just-split-it)))
