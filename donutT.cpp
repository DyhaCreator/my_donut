                                //--      
                         #include <cmath>                       
                       #include <string>//-                                            
                    #include <iostream>/*----*/
                   int main(){float rx=0;while(true
                  ){float s=sin(rx),c=cos(rx); std::
              string sc;for(float ry=-1;ry<1;ry+=0.04
              ){for(float rx=-1;rx<1;rx+=0.03){float rX
              =0,rY=-2,rZ=0;bool b=1;for(int i=0;i<5;i++
              ){rX+=cos(ry)*sin(rx)*0.6;rY+=cos(ry)*cos
              (rx)*0.6;rZ+=sin(ry)*0.6;for(int j=0;j<20;
              j++){float X=sin((float)j/20 *M_PI*2),Y=cos
             ((float)j/20*M_PI         *2),Z=0,NZ=X*c-Z*
             s,NY=Y,NX=X*s+               Z*c;X=NX;Y=NY;
             Z = NZ;NX = X                ;NY = Y*c+Z*s;
             NZ=-Y*s+Z * c;                X=NX;Y=NY; Z=
            NZ;float l=(rX                 -X)*(rX-X)+(
            rY-Y)*(rY -Y)+                 (rZ-Z)*(rZ-Z)
            -0.2;if(l<0.01                 ){b=0;break;}
             }}if(b){sc+=                 ' ';}else{sc+=
             '#'; } } sc+=               "\n";}std::cout
             <<sc << std::               endl;rx += 0.1;
               }  return 0;  }      //##############//
               //###############    ################//              
               //##################################//             
               //#################################//               
                 //##############################//                
                  //############################//                 
                   //##########################//                  
                    //#######################//                    
                       //#################//                       
                         //#############//                         
                                ////                               