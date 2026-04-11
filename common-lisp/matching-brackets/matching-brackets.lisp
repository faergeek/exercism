(defpackage :matching-brackets
  (:use :cl)
  (:export :pairedp))

(in-package :matching-brackets)

(defvar *open-to-close-bracket*
  (list
    (cons #\[ #\])
    (cons #\{ #\})
    (cons #\( #\))))

(defvar *close-to-open-bracket*
  (mapcar (lambda (x) (cons (cdr x) (car x)))
          *open-to-close-bracket*))

(defun pairedp (value)
  (loop for ch across value
        with bracket-stack = nil
        when (assoc ch *open-to-close-bracket*)
        do (setf bracket-stack (cons ch bracket-stack))
        when (assoc ch *close-to-open-bracket*)
        do (let ((bracket-stack-top (car bracket-stack)))
             (if (and bracket-stack-top
                      (char=
                        bracket-stack-top
                        (cdr (assoc ch *close-to-open-bracket*))))
               (setf bracket-stack (cdr bracket-stack))
               (return nil)))
        finally (return (null bracket-stack))))
