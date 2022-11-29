function bool = detect(mtx, x1, y1, x2, y2)
    % ========================== ����˵�� ==========================
    
    % ��������У�mtxΪͼ���ľ������������ĸ�ʽ��
    % [ 1 2 3;
    %   0 2 1;
    %   3 0 0 ]
    % ��ͬ�����ִ�����ͬ��ͼ����0����˴�û�п顣
    % ������[m, n] = size(mtx)��ȡ������������
    % (x1, y1)�루x2, y2��Ϊ���жϵ�������±꣬���ж�mtx(x1, y1)��mtx(x2, y2)
    % �Ƿ������ȥ��
    
    % ע��mtx��������Ϸ�����ͼ����λ�ö�Ӧ��ϵ���±�(x1, y1)��������������
    % ������������½�Ϊԭ�㽨������ϵ��x�᷽���x1����y�᷽���y1��
    
    % �������bool = 1��ʾ������ȥ��bool = 0��ʾ������ȥ��
    
    %% �����������Ĵ���O(��_��)O
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