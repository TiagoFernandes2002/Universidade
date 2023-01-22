n_epocas = 2000; %numeros de epocas
alpha = 0.9; % factor de aprendizagem

%vetor soma dos erros
sse = zeros(1,n_epocas);
N=4; %nÂº de amostras

%amostras de entrada da funcao XOR
X =[ 0 0 1;
     0 1 1;
     1 0 1;
     1 1 1];
T = [0 1 1 0];


%inicializaÃ§Ã£o aleatoria dos pesos
%w1- 2x3  w2 1x3
W1 = 2+rand(2,3) -1
W2 = 2+rand(1,3) - 1


for epoch =1:n_epocas
    sum_sq_error=0;
    for k = 1:N
        x = X(k,:)';
        t = T(k);

        %soma da camada de entrada
        g1 = W1*x;

        %funçao de ativação sigmoidal
        y1 = sig(g1);

        %adiçao a saida da camada escondida y1 da entrada de bias com +1
        %resulta em y1_b
        y1_b = [y1
                1];

        %soma da camada de saída
        g2 = W2*y1_b;
        %funçao de ativaçao sigmoidal
        y2 = sig(g2);

        %erro da camada de saida
        e = t - y2;
        %calculo do delta da camada de saida sigmoide
        delta2 = y2.*(1-y2).*e;

        %atualização da soma dos erros quadráticos
        sum_sq_error = sum_sq_error+ e^2;

        %erro da camada escondida
        e1 = W2'*delta2;
        %erro sem o bias
        e1_b = e1(1:2);

        %calculo do delta da camada de saida
        delta1 = y1.*(1-y1).*e1_b;

        %atualizaçao dos pesos da camada escondida
        dW2 = alpha*delta2*y1_b'; %com bias
        W2 = W2 + dW2;

        %atualizaçao dos pesos da camada de entrada
        dW1 = alpha*delta1*x';
        W1 = W1 + dW1;
    end
    sse(epoch)= (sum_sq_error)/N;
end

for k = 1:N

    x = X(k,:)';
    g1 = W1*x;

    %sigmoide
    y1 = sig(g1);

    %y1 mais uma entrada de bias
    y1_b = [y1
            1];

    g2 = W2*y1_b;

    %saida prevista XOR
    y_plot(k) = sig(g2);
end
y_plot; 
It = 1:1:n_epocas;
plot(It,sse,'r-','LineWidth',2)
xlabel('Época')
ylabel('SSE')
title('Função de ativação: sigmoide')
