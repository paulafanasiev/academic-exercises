TITLE LAB6 
.Model Small; задание модели "Small"
.STACK 100h; сегмент стека в 100h байт 
.Code; сегмент кода 
EXTRN INPUT:far, OUTPUT1:far, OUTPUT2:far 

START: 
call OUTPUT2; вызов процедуры OUTPUT2 для сообщения пользователю о необходимости ввода символа
CALL_INPUT: 
call INPUT; ВЫЗОВ процедуры INPUT
cmp al, 41h; сравнение введённого символа с кодом символа А
je CALL_OUTPUT1; если введённы символ совпал с кодом символа А, то переходим к вызову процедуры OUTPUT1
call OUTPUT2; вызов процедуры OUTPUT2 для сообщения пользователю о необходимости ввода корректного символа
jmp CALL_INPUT; Переход к метке повторного вызова процедуры INPUT

CALL_OUTPUT1: 
call OUTPUT1; вызов процедуры OUTPUT1, значит введённый символ соответствует заданному и переходим к заключительным действиям 
int 21h 
mov ax,4c00h 
int 21h 
END START
