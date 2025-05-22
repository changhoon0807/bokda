function Omega = randiw(Omega0_df, df)
% Omega0_df = Omega(inverse wishart ����)�� ��밪 X ������(df)
% inverse wishart ������ ������ Omega�� ��밪 = Omega0_df/df;
% df = ������, �������� Ŭ���� ���� prior

Omega0_df_inv = invpd(Omega0_df);
Omega_inv = randwishart(Omega0_df_inv, df);
Omega = invpd(Omega_inv);

end