; Дополнительный исходный файл
TITLE OUTPUT1 
PUBLIC OUTPUT1; Объявляем процедуру OUTPUT1 публичной для работы других модулей 
.model small; задание модели "Small"
.stack 100h; сегмент стека в 100h байт 
.code; сегмент кода 

OUTPUT1 PROC far 
push bp 
push ax 
push dx 
mov bp,sp 	
mov ah, 09h ; AH = 9 (прерывание для вывода)
mov dx,[bp + 10] 
int 21h ; вывод сообщения на экран 
pop dx
pop ax
pop bp
ret; возврат управления из процедуры вызывающей программе 
OUTPUT1 endp 
End
