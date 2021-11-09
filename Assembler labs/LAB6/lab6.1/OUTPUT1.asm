; Дополнительный исходный файл
TITLE OUTPUT1 
PUBLIC OUTPUT1; Объявляем процедуру OUTPUT1 публичной для работы других модулей 
.model small; задание модели "Small"
.stack 100h; сегмент стека в 100h байт 
.data; сегмент данных 
mes1 db 10,13, 'Key A pressed - communication ended. $' 
.code; сегмент кода 

OUTPUT1 PROC far 
mov ax,@data; указываем на начало данных 
mov ds,ax ; пересылка в DS адреса начала сегмента данных 
mov ah, 09h ; AH = 9 (прерывание для вывода)
lea dx,mes1; загрузка в регистр адрес mes1 
int 21h ; вывод сообщения на экран 
ret; возврат управления из процедуры вызывающей программе 
OUTPUT1 endp 
End
