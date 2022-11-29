function steps = omg(mtx)
    % -------------- �������˵�� --------------
    
    %   ��������У�mtxΪͼ���ľ������������ĸ�ʽ��
    %   [ 1 2 3;
    %     0 2 1;
    %     3 0 0 ]
    %   ��ͬ�����ִ�����ͬ��ͼ����0����˴�û�п顣
    %   ������[m, n] = stemp1ze(mtx)��ȡ������������
    
    %   ע��mtx��������Ϸ�����ͼ����λ�ö�Ӧ��ϵ���±�(x1, y1)��������������
    %   ������������½�Ϊԭ�㽨������ϵ��x�᷽���x1����y�᷽���y1��
    
    % --------------- �������˵�� --------------- %
    
    %   Ҫ�����ó��Ĳ����������steps������,��ʽ���£�
    %   steps(1)��ʾ��������
    %   ֮��ÿ�ĸ���x1 y1 x2 y2�������mtx(x1,y1)��mtx(x2,y2)��ʾ�Ŀ�������
    %   ʾ���� steps = [2, 1, 1, 1, 2, 2, 1, 3, 1];
    %   ��ʾһ������������һ����mtx(1,1)��mtx(1,2)��ʾ�Ŀ�������
    %   �ڶ�����mtx(2,1)��mtx(3,1)��ʾ�Ŀ�������
    
    %% --------------  �������������Ĵ��� O(��_��)O~  -----------
     [m, n] = size(mtx);
    none=zeros(1,m*n*2+1);
    steps=none;
    step=0;
    bool=1;
    while(bool)
        bool=0;
        for temp1=1:m*n-1
            if(mtx(floor((temp1-1)/n)+1,mod(temp1-1,n)+1)~=0)
                for temp2=temp1+1:m*n
                    if(mtx(floor((temp1-1)/n)+1,mod(temp1-1,n)+1)==mtx(floor((temp2-1)/n)+1,mod(temp2-1,n)+1)&&detect(mtx,floor((temp1-1)/n)+1,mod(temp1-1,n)+1,floor((temp2-1)/n)+1,mod(temp2-1,n)+1))
                        steps(step*4+2)=floor((temp1-1)/n)+1;
                        steps(step*4+3)=mod(temp1-1,n)+1;
                        steps(step*4+4)=floor((temp2-1)/n)+1;
                        steps(step*4+5)=mod(temp2-1,n)+1;
                        mtx(floor((temp1-1)/n)+1,mod(temp1-1,n)+1)=0;
                        mtx(floor((temp2-1)/n)+1,mod(temp2-1,n)+1)=0;
                        step=step+1;
                        bool=1;
                        break;
                    end
                end
            end
        end
    end
    steps(1)=step;
    steps=steps(1:step*4+1);

