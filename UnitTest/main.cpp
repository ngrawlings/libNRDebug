//
//  main.cpp
//  UnitTest
//
//  Created by Nyhl Rawlings on 07/09/2018.
//  Copyright © 2018 Liquidsoft Studio. All rights reserved.
//

#include <iostream>
#include <libnrdebug/UnitTests.h>

using namespace nrcore;

bool testUnitTesting() {
    UnitTests::fail("Faield by calling fail");
    return true;
}

int main(int argc, const char * argv[]) {
    UnitTests tests;
    
    tests.addTest("testUnitTesting", testUnitTesting);
    tests.run();
    
    return 0;
}
