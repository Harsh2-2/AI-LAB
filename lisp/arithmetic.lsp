(defun arithmetic-operations (a b)
  (format t "Given numbers: ~a and ~a~%" a b)
  (format t "Addition: ~a + ~a = ~a~%" a b (+ a b))
  (format t "Subtraction: ~a - ~a = ~a~%" a b (- a b))
  (format t "Multiplication: ~a * ~a = ~a~%" a b (* a b))
  (format t "Division: ~a / ~a = ~a~%" a b (/ a b))
  (format t "Modulus: ~a mod ~a = ~a~%" a b (mod a b)))

; Call the function with any two numbers
(arithmetic-operations 10 3)
