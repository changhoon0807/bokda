function [PCm, eigen_valm, Vm, CORM ] = PCA_K(Y, is_COV)
% Y = T by k
% PCm = T by k
if nargin == 1
    is_COV = 0;
end

% 1 �ܰ�: ��������� ����ϱ�
if is_COV == 0
   CORM = corrcoef(Y);
elseif is_COV == 1
   CORM = cov(Y);
end

% 2 �ܰ�: Ư����, Ư������ ����ϱ�
[V, D] = eig(CORM);

% V = Ư������, D�� �밢���� = Ư����
   
% 3 �ܰ�
eigen_val = diag(D); % 3 by 1
[eigen_val, index] = sort(eigen_val, 'descend'); % Ư���� �����ϱ�
Vm = V(:, index);% Ư������ �����ϱ�

eigen_valm = [eigen_val, eigen_val/sumc(eigen_val)];

% 4 �ܰ�: PC ����ϱ�
if is_COV == 0
   stand_Y = standdc(Y);
   PCm = stand_Y*Vm; % T by 3
elseif is_COV == 1
   PCm = Y*Vm; % T by 3
end

disp(['Ư���� = ', num2str(eigen_val'/sumc(eigen_val))]);
end