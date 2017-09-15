#matlab计算水平圆筒封头局部容积参数表计算代码
#192.168.1.184:99
clear  all
i=0;
for x=0:0.01:1.0;
    k=2*x^2*(3/2-x);
    fprintf('%1.4f,',k)
    i=i+1;
    if i== 10 
        fprintf('\r\n');
        i=0;
    end
end
