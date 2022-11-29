function bool = detect(mtx, x1, y1, x2, y2)
    % ========================== 参数说明 ==========================
    
    % 输入参数中，mtx为图像块的矩阵，类似这样的格式：
    % [ 1 2 3;
    %   0 2 1;
    %   3 0 0 ]
    % 相同的数字代表相同的图案，0代表此处没有块。
    % 可以用[m, n] = size(mtx)获取行数和列数。
    % (x1, y1)与（x2, y2）为需判断的两块的下标，即判断mtx(x1, y1)与mtx(x2, y2)
    % 是否可以消去。
    
    % 注意mtx矩阵与游戏区域的图像不是位置对应关系。下标(x1, y1)在连连看界面中
    % 代表的是以左下角为原点建立坐标系，x轴方向第x1个，y轴方向第y1个
    
    % 输出参数bool = 1表示可以消去，bool = 0表示不能消去。
    
    %% 在下面添加你的代码O(∩_∩)O
[m, n] = size(mtx);
bool = 0;
if(mtx(x1,y1)~=mtx(x2,y2))
return;
end
mtx(x1,y1)=0;
mtx(x2,y2)=0;
test1=(~any(mtx(1:x1,y1))&&~any(mtx(1:x2,y2)))||(~any(mtx(x1:m,y1))&&~any(mtx(x2:m,y2)));
test2=(~any(mtx(x1,1:y1))&&~any(mtx(x2,1:y2)))||(~any(mtx(x1,y1:n))&&~any(mtx(x2,y2:n)));
if(test1)
bool=1;
return;
end
if(test2)
bool=1;
return;
end
for i=1:n
    test3=~any(mtx(x1,min(y1,i):max(y1,i)))&&~any(mtx(x2,min(y2,i):max(y2,i)))&&~any(mtx(min(x1,x2):max(x1,x2),i));
    if(test3)
        bool=1;
        return;
    end
end
for i=1:m
    test4=~any(mtx(min(x1,i):max(x1,i),y1))&&~any(mtx(min(x2,i):max(x2,i),y2))&&~any(mtx(i,min(y1,y2):max(y1,y2)));
    if(test4)
        bool=1;
        return;
    end
end



end