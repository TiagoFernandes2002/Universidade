 %Conjunto de dados
 %Total de 120 amostras, K=40 amostras para cada classe
 K=100;

 %Importa dados
 %X_train = Classe A; Y_train - Classe B;
 %X_Teste - Dados para teste de RN
 iris

 % Visualização das classes
 A=X_train';
 B=Y_train';

% %  Desenho dos pontos

 % A: square - s
 plot(A(1,:),A(2,:),'bs')
 grid on
 hold on

 % B: +
 plot(B(1,:),B(2,:),'r+')


 % % topologia da rede 2x5x2
 % % Com adição de um neuronio de bias na camada escondida
 % % Inicialização dos pesos no intervalo [-1 1]
 % W1: 3x2
 W1 = 2*rand(4,2) - 1
 % W2 4(-3+bias)x2
 W2 = 2*rand(2,5) - 1
 
 %Com uma entrada de bias na camada de entrada
 %Bias=+1
 bias_A= ones(K,1);
 %Adiciona o vector de bias ao conjunto A
 X_train=[X_train,bias_A]';
 %Conjunto de saida da Classe A
 T_A=ones(K,2).*[1 0];

 bias_B= ones(K,1);
 %adiciona o vector de bias ao conjunto B
 Y_train=[Y_train,bias_B];
 %conjunto de saida da classe B;
 T_B=ones(K,2).*[0 1];


 
 %Concatenação dos 2 vetores de entrada
 X= [X_train;
     Y_train]

 % Concatenação dos 2 vetores de saida
 T= [T_A;
     T_B]


 %--------------------------------------------
 %--------------------------------------------
 N = 2*K; %Numero total de amostras
 n_epochs=10000; %numero de epocas
 SSE = zeros(1,n_epochs); %inicialização da soma do erro
 alpha=0.9; %taxa de aprendizagem
 

 % Ciclo de treino da RN
 for epoch = 1:n_epochs
        sum_sq_error=0;
        for K = 1:N
            x = X(K,:)';
            t = T(K,:)';
            %Soma da camada de entrada
            g1 = W1*x;
            %Saida da camada de entrada
            y1 = sig(g1);
            %------------------
            % Com bias na camada escondida
            y1_b = [y1
                    1];
            % soma de cada saida
            g2 = W2*y1_b;
            %Saida da camada de saida
            y2 = sig(g2);
            %Erro da camada de saida
            e = t -y2;
            % Delta da camada de saida
            delta2 = y2.*(1-y2).*e;
            
            
            % ataualização do SSE
            sum_sq_error = sum_sq_error + sum(e.^2);

            %Erro da camada escondida
            e1 = W2'*delta2;
            %Tirando bias
            e1_b = e1 (1:4);

            %atualização dos pesos
            dW2 = alpha*delta2*y1_b';
            W2 = W2 + dW2;

            %com bias
            delta1 = y1.*(1-y1).*e1_b;

            dW1 = alpha*delta1*x';
            W1 = W1 + dW1;
       
        end
        
        SSE(epoch)= (sum_sq_error)/N;
        fprintf(1,'E=%d\t SSE=%3.6f\n',epoch,SSE(epoch));
 
 end
y_plot=zeros(N,3);

%teste da RN
for K = 1:N
    x = X(K,:)';
    g1 = W1*x;
    %Sigmoide
    y1 =sig(g1);
    %y1 adicionada com entrada de bias
    y1_b = [y1
             1];
    %soma e saida
    g2 = W2*y1_b;
    y2 = sig(g2);
    %Para o grafico
    y_plot(k,:) = y2;
end

% teste para limite da classificação
limite=0.9;
y_bin = y_plot>limite


%Grafico
figure
It=1:1:n_epochs;
plot(It,SSE,'r-','LineWidth',2)
xlabel('Época')
ylabel('SSE')
title('Função de ativação: Sigmóide')




