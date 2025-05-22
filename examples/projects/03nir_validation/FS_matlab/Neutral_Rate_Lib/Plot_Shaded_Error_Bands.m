function H = Plot_Shaded_Error_Bands(x, y)
% Written by ����ȣ. �ƹ��� ���Ƿ� �����ؼ� ����� �� �ֽ��ϴ�.
% y = N by 3, �Ǵ� N by 5, �Ǵ� N by 7
% x = N by 1,  X ��

% ���� ���, y�� ���� ���� 5�̰�, 3��° ���� ���, 1�� 5���� 95% �ŷڱ���, 2���� 4���� 80% �ŷڱ�������
% �����ؼ� �׸��� �׸� �� �ֽ��ϴ�.
% 1��-ahead, 2��-ahead��,.., H��-ahead ����ġ�� �ŷڱ����� ���ÿ� �׸� �� ������ �� �ֽ��ϴ�.

[rs, cs] = size(y); % ���� ��
mc = ceil(cs/2);
m = y(:, mc); % ����ġ
y = y';
x = x';

%% ��ռ� �׸���
figure
H.mainLine = plot(x, m', 'b-o', 'LineWidth', 4);
xlim([x(1)-0.5 x(end)+0.5]); % X ���� ����
xtick = x;
set(gca,'XTick', xtick);
title([num2str(1), '����� ', num2str(rs), '������� ��������'])
xlabel('Forecast horizon','FontSize',11)
ylabel('(%)','FontSize',11)

%% ù ��° �ŷڱ��� �׸���
hold on;
col = [0, 0, 0]; % ������
patchSaturation=0.6;
patchColor=col+(1-col)*(1-patchSaturation);
px=[x,fliplr(x)];
py=[y(mc-1,:), fliplr(y(mc+1,:))];
H1.patch = patch(px,py,1,'FaceColor',patchColor,'EdgeColor','none', 'facealpha',patchSaturation);
legend([H.mainLine, H1.patch], ...
    '����ġ', '95%',  ...
    'Location', 'Northwest');

%% �� ��° �ŷڱ��� �׸���
if cs > 3
    patchSaturation=0.45;
    patchColor=col+(1-col)*(1-patchSaturation);
    hold on;
    py=[y(mc-2,:), fliplr(y(mc-1,:))];
    H2.patch = patch(px,py,1,'FaceColor',patchColor,'EdgeColor','none', 'facealpha',patchSaturation);
    py=[y(mc+1,:), fliplr(y(mc+2,:))];
    H2.patch = patch(px,py,1,'FaceColor',patchColor,'EdgeColor','none', 'facealpha',patchSaturation);
    legend([H.mainLine, H1.patch, H2.patch], ...
        '����ġ', '80%','95%', ...
        'Location', 'Northwest');
    
    %% �� ��° �ŷڱ��� �׸���
    if cs > 5
        patchSaturation=0.3;
        patchColor=col+(1-col)*(1-patchSaturation);
        hold on;
        py=[y(mc-3,:), fliplr(y(mc-2,:))];
        H3.patch = patch(px,py,1,'FaceColor',patchColor,'EdgeColor','none', 'facealpha',patchSaturation);
        py=[y(mc+2,:), fliplr(y(mc+3,:))];
        H3.patch = patch(px,py,1,'FaceColor',patchColor,'EdgeColor','none', 'facealpha',patchSaturation);
        legend([H.mainLine, H1.patch, H2.patch, H3.patch], ...
            '����ġ', '50%', '80%','95%', ...
            'Location', 'Northwest');
        
    end
end

end