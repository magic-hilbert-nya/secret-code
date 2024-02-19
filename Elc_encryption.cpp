int main()
{

    

    Field u("3B91E4BA", "9C206D15", "8F7EA5EF", "8C603D14", "9B5D7DDF", "F575F77F", "D5D7DDFF", "575F77EC");

    Field v("D99CC546", "CB702628", "1EF0CDE6", "910D035F", "B5954E2F", "42358F83", "9954E2F4", "2358F848");
    

    //shell();

    Field u_1("3B91E4BA", "9C206D15", "8F7EA5EF", "8C553D14", "9B5E7DDF", "F575F77F", "D5D7DDFF", "575FA7EC");

    Field a = a_t(u_1);
    Field b = b_t(u_1);



    
    Field p = solveEqu(a, b);


    Ellc x(u_1,p);
    if (x.Ellc_on()) { std::cout << "true"; }   //检验x(u,v)是否在点curve x上。



	
}



