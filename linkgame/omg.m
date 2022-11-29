function steps = omg(mtx)
    % -------------- 输入参数说明 --------------
    
    %   输入参数中，mtx为图像块的矩阵，类似这样的格式：
    %   [ 1 2 3;
    %     0 2 1;
    %     3 0 0 ]
    %   相同的数字代表相同的图案，0代表此处没有块。
    %   可以用[m, n] = stemp1ze(mtx)获取行数和列数。
    
    %   注意mtx矩阵与游戏区域的图像不是位置对应关系。下标(x1, y1)在连连看界面中
    %   代表的是以左下角为原点建立坐标系，x轴方向第x1个，y轴方向第y1个
    
    % --------------- 输出参数说明 --------------- %
    
    %   要求最后得出的操作步骤放在steps数组里,格式如下：
    %   steps(1)表示步骤数。
    %   之后每四个数x1 y1 x2 y2，代表把mtx(x1,y1)与mtx(x2,y2)表示的块相连。
    %   示例： steps = [2, 1, 1, 1, 2, 2, 1, 3, 1];
    %   表示一共有两步，第一步把mtx(1,1)和mtx(1,2)表示的块相连，
    %   第二步把mtx(2,1)和mtx(3,1)表示的块相连。
    
    %% --------------  请在下面加入你的代码 O(∩_∩)O~  -----------
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

