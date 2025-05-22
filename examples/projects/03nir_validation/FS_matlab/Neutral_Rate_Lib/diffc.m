function Y = diffc(X, Lag)
% X�� T by Lag ���
% Y�� (T-Lag) by K ������, ������ �ۼ�Ʈ

isX_positive = X > 0;

if minc(isX_positive) == 0
    disp('error: INPUT�� 0 �Ǵ� ������ entry�� ����')
    return
end

lnX = log(X);
Y = 100*(lnX(Lag+1:end, :) - lnX(1:end-Lag, :));

end