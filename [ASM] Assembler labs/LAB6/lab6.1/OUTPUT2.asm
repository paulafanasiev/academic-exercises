; Дополнительный исходный файл
TITLE OUTPUT2 
PUBLIC OUTPUT2; Объявляем процедуру OUTPUT2 публичной для работы других модулей 
.model small; задание модели "Small"
.stack 100h; сегмент стека в 100h байт 
.data; сегмент данных 
mes2 db 10,13, 'Press the A key: $' 
.code; сегмент кода 

OUTPUT2 PROC far 
mov ax,@data; указываем на начало данных 
mov ds,ax ; пересылка в DS адреса начала сегмента данных 
mov ah, 09h ; AH = 9 (прерывание для вывода)
lea dx,mes2; загрузка в регистр адрес mes2 
int 21h ; вывод на экран сообщения 
ret; возврат управления из процедуры вызывающей программе 
OUTPUT2 endp 
end
