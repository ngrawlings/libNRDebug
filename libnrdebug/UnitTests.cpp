//
//  UnitTests.cpp
//  NrDebug
//
//  Created by Nyhl Rawlings on 07/09/2018.
//  Copyright © 2018 Liquidsoft Studio. All rights reserved.
//

#include "UnitTests.h"

namespace nrcore {
    
    void UnitTests::addTest(Ref<UNITTEST_ENTRY> test) {
        this->tests.add(test);
    }
    
    void UnitTests::addTests(RefArray<Ref<UNITTEST_ENTRY>> tests, int count) {
        for(int i=0; i<count; i++)
            this->tests.add(tests.getPtr()[i]);
    }
    
    bool UnitTests::run() {
        bool ret = true;
        
        if (tests.length()) {
            LINKEDLIST_NODE_HANDLE node = tests.firstNode();
            do {
                Ref<UNITTEST_ENTRY> test = tests.get(node);
                try {
                    if (test.getPtr()->method()) {
                        printf("%s succeeded\r\n", (char*)test.getPtr()->name);
                    } else {
                        printf("%s failed\r\n", (char*)test.getPtr()->name);
                        ret = false;
                    }
                } catch (String err) {
                    printf("%s failed with the following error: %s\r\n", (char*)test.getPtr()->name, (char*)err);
                    ret = false;
                }
            } while ((node = tests.nextNode(node)));
        }
        
        return ret;
    }
    
}
