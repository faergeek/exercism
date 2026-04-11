(defpackage :robot-name
  (:use :cl)
  (:export :build-robot :robot-name :reset-name))

(in-package :robot-name)

(defun random-char (start-char end-char)
  (let ((start-code (char-code start-char))
        (end-code (char-code end-char)))
    (code-char (+ start-code (random (1+ (- end-code start-code)))))))

(defun random-letter ()
  (random-char #\A #\Z))

(defun random-digit ()
  (random-char #\0 #\9))

(defun generate-robot-name ()
  (apply #'concatenate
         (cons 'string
               (mapcar (lambda (ch) (coerce (list ch) 'string))
                       (list
                         (random-letter)
                         (random-letter)
                         (random-digit)
                         (random-digit)
                         (random-digit))))))

(defvar *robots-by-name* (make-hash-table :test 'equal))

(defun generate-unique-robot-name ()
  (let ((name (generate-robot-name)))
    (loop while (nth-value 1 (gethash name *robots-by-name*))
          do (setf name (generate-robot-name))
          finally (return name))))

(defstruct robot
  (name (generate-unique-robot-name) :type string))

(defun build-robot ()
  (let ((robot (make-robot)))
    (setf (gethash (robot-name robot) *robots-by-name*) robot)))

(defun reset-name (robot)
  (setf (robot-name robot) (generate-unique-robot-name)))
