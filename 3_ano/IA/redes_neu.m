n_epocas = 200; %numeros de epocas
alpha = 9; % factor de aprendizagem

%vetor soma dos erros
sse = zeros(1,n_epocas);
N=4; %nº de amostras

%amostras de entrada da funcao XOR
X =[ 0 0 1;
     0 1 1;
     1 0 1;
     1 1 1];
T = [0 1 1 0];


%inicialização aleatoria dos pesos
%w1- 2x3  w2 1x3
W1 = 2+rand(2,3) -1
W2 = 2+rand(1,3) - 1
