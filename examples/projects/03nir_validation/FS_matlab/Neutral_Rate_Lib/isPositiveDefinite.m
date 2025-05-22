function x = isPositiveDefinite(A)
%Function to check whether a given matrix A is positive definite
%Author Mathuranathan for https://www.gaussianwaves.com
%Returns x=1, if the input matrix is positive definite
%Returns x=0, if the input matrix is not positive definite
%Throws error if the input matrix is not symmetric

    %Check if the matrix is symmetric
    [m,n]=size(A); 
    if m~=n
        error('A is not Symmetric');
    end
    
    %Test for positive definiteness
    x=1; %Flag to check for positiveness
    for i=1:m
        subA=A(1:i,1:i); %Extract upper left kxk submatrix
        if(det(subA)<=0) %Check if the determinent of the kxk submatrix is +ve
            x=0;
            break;
        end
    end
%     
%     if x
%         disp('Given Matrix is Positive definite');
%     else
%         disp('Given Matrix is NOT positive definite');
%     end      
end