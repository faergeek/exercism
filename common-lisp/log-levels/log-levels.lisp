(defpackage :log-levels
  (:use :cl)
  (:export :log-message :log-severity :log-format))

(in-package :log-levels)

(defun log-message (log-string)
  (subseq log-string 8))

(defun log-severity (log-string)
  (let ((sev-str (subseq log-string 1 5)))
    (cond 
      ((string-equal sev-str "info") :everything-ok)
      ((string-equal sev-str "warn") :getting-worried)
      ((string-equal sev-str "ohno") :run-for-cover))))

(defun log-format (log-string)
  (let ((msg (log-message log-string)))
    (case (log-severity log-string)
      (:everything-ok (string-downcase msg))
      (:getting-worried (string-capitalize msg))
      (:run-for-cover (string-upcase msg)))))
