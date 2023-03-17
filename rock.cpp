#include <iostream>
#include <cmath>

using namespace std;

class Rock {
    private:
        double gravitation; // გრავიტაციის ძალა
        double velocity; // მეტრი წამში
        double alpha; // გრადუსული ზომა რადიანებში
        
    public:
        Rock(double gravitation,double velocity,double angle) { input(gravitation,velocity,angle);
        };
        void input(double gravitation,double velocity,double angle) {
            this -> gravitation = fabs(gravitation);
            this -> velocity = fabs(velocity);
            this -> alpha = M_PI/180 * angle;
            
        };
        
        double getHeight() {
            return ( pow(velocity,2) * pow(sin(alpha),2) ) / (2*gravitation);
        };
        
        double getDistance() {
            return (pow(velocity,2) * fabs(sin(2 * alpha))) / gravitation;
        };
        
        double getTIme() {
            return (2 * velocity * fabs(sin(alpha))) / gravitation;
        };
}; 

int main() {
    
    Rock x = Rock(3.721,100,100);
    cout<<x.getHeight()<<endl;
    cout<<x.getDistance()<<endl;
    cout<<x.getTIme()<<endl;
    
    return 0;
}
