
(cl:in-package :asdf)

(defsystem "learning_communication-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "addTwoInts" :depends-on ("_package_addTwoInts"))
    (:file "_package_addTwoInts" :depends-on ("_package"))
  ))