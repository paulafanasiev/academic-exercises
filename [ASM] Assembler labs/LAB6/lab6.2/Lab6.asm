TITLE LAB6 
.Model Small; задание модели "Small"
.STACK 100h; сегмент стека в 100h байт 
.data; сегмент данных 
	PressedKey db ? 
	mes1 db 10,13, 'Key A pressed - communication ended. $' 
	mes2 db 10,13, 'Press the A key: $' 
.Code; сегмент кода 
EXTRN INPUT:far, OUTPUT1:far, OUTPUT2:far 

START: 
	mov ax,@data ; указываем на начало данных 
	mov ds,ax ; пересылка в DS адреса начала сегмента данных 
	lea dx,mes2 
	push dx 
	call OUTPUT2; вызов процедуры OUTPUT2 для сообщения пользователю о необходимости ввода символа
	add sp,2
CALL_INPUT: 
	lea dx,PressedKey 
	push dx 
	call INPUT; ВЫЗОВ процедуры INPUT
	add sp,2 ; 
	lea di,PressedKey 
	mov al,[di] 
	cmp al, 41h; сравнение введённого символа с кодом символа А
		je CALL_OUTPUT1; если введённы символ совпал с кодом символа А, то переходим к вызову процедуры OUTPUT1
	lea dx,mes2 
	push dx 
	CALL OUTPUT2; вызов процедуры OUTPUT2 для сообщения пользователю о необходимости ввода корректного символа
	add sp,2 
	jmp CALL_INPUT; Переход к метке повторного вызова процедуры INPUT

CALL_OUTPUT1: 
	lea dx,mes1 
	push dx 
	call OUTPUT1; вызов процедуры OUTPUT1, значит введённый символ соответствует заданному и переходим к заключительным действиям 
	add sp,2 
int 21h 
mov ax,4c00h 
int 21h 
END START
