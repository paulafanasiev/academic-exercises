; Дополнительный исходный файл
TITLE INPUT 
PUBLIC INPUT ; Объявляем процедуру INPUT публичной для работы других модулей 
.model small 
.stack 100h 
.code 
INPUT PROC far 
push bp
push ax
push di
mov bp, sp
mov ah, 1 ; вызываем функцию ввода символа 
int 21h ; прерывание для отработки функции 
mov di,[bp+10]
mov [di],al
pop di 
pop ax
pop bp
ret ; возврат к текущему месту в программе 
INPUT endp 
end
