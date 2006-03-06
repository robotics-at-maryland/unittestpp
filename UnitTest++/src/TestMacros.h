#ifndef UNITTEST_TESTMACROS_H
#define UNITTEST_TESTMACROS_H


#define TEST(Name) \
    class Test##Name : public UnitTest::Test \
    { \
    public: \
        Test##Name() : Test(#Name, __FILE__, __LINE__) {} \
    private: \
        virtual void RunImpl(UnitTest::TestResults& testResults_); \
    } test##Name##Instance; \
    UnitTest::TestRegistrar registrar##Name (UnitTest::Test::s_listHead, UnitTest::Test::s_listTail, &test##Name##Instance); \
    void Test##Name::RunImpl(UnitTest::TestResults& testResults_)
    

#define TEST_FIXTURE(Fixture, Name) \
    struct Fixture##Name##Helper : public Fixture {                                             \
        Fixture##Name##Helper(char const* testName) : m_testName(testName) {}                       \
        void RunTest(UnitTest::TestResults& testResults_);                                            \
        char const* const m_testName;   \
    };                                                                                  \
    class Test##Fixture##Name : public UnitTest::Test \
    { \
    public: \
        Test##Fixture##Name() : Test(#Name, __FILE__, __LINE__) {} \
    private: \
        virtual void RunImpl(UnitTest::TestResults& testResults_); \
    } test##Fixture##Name##Instance; \
    UnitTest::TestRegistrar registrar##Fixture##Name (UnitTest::Test::s_listHead, UnitTest::Test::s_listTail, &test##Fixture##Name##Instance); \
    void Test##Fixture##Name::RunImpl(UnitTest::TestResults& testResults_)  { \
        Fixture##Name##Helper mt(m_testName);                                                  \
        mt.RunTest(testResults_);                                                          \
    } \
    void Fixture##Name##Helper::RunTest(UnitTest::TestResults& testResults_)


#define TEST_FIXTURE_CTOR(Fixture, CtorParams, Name) \
    struct Fixture##Name##Helper : public Fixture {                                             \
        Fixture##Name##Helper(char const* testName) : Fixture CtorParams, m_testName(testName) {}   \
        void RunTest(UnitTest::TestResults& testResults_);                                            \
        char const* const m_testName;   \
    };                                                                                  \
    class Test##Fixture##Name : public UnitTest::Test \
    { \
    public: \
        Test##Fixture##Name() : Test(#Name, __FILE__, __LINE__) {} \
    private: \
        virtual void RunImpl(UnitTest::TestResults& testResults_); \
    } test##Fixture##Name##Instance; \
    UnitTest::TestRegistrar registrar##Fixture##Name (UnitTest::Test::s_listHead, UnitTest::Test::s_listTail, &test##Fixture##Name##Instance); \
    void Test##Fixture##Name::RunImpl(UnitTest::TestResults& testResults_)  { \
        Fixture##Name##Helper mt(m_testName);                                                  \
        mt.RunTest(testResults_);                                                          \
    } \
    void Fixture##Name##Helper::RunTest(UnitTest::TestResults& testResults_)
    

#endif

