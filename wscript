#!/usr/bin/env python
# encoding: utf-8

def options(opt):
    opt.load('compiler_cxx waf_unit_test')

def configure(conf):
    conf.load('compiler_cxx waf_unit_test')

def build(bld):
    source = [
        'AssertException.cpp',
        'Test.cpp',
        'Checks.cpp',
        'TestRunner.cpp',
        'TestResults.cpp',
        'TestReporter.cpp',
        'TestReporterStdout.cpp',
        'ReportAssert.cpp',
        'TestList.cpp',
        'TimeConstraint.cpp',
        'TestDetails.cpp',
        'MemoryOutStream.cpp',
        'DeferredTestReporter.cpp',
        'DeferredTestResult.cpp',
        'XmlTestReporter.cpp',
        'CurrentTest.cpp',
        'Posix/SignalTranslator.cpp',
        'Posix/TimeHelpers.cpp'
        ]
    bld.stlib( target = 'UnitTest++',
               source = ['src/'+x for x in source],
               install_path = '${LIBDIR}' )

    source = [
        'Main.cpp',
        'TestAssertHandler.cpp',
        'TestChecks.cpp',
        'TestUnitTest++.cpp',
        'TestTest.cpp',
        'TestTestResults.cpp',
        'TestTestRunner.cpp',
        'TestCheckMacros.cpp',
        'TestTestList.cpp',
        'TestTestMacros.cpp',
        'TestTimeConstraint.cpp',
        'TestTimeConstraintMacro.cpp',
        'TestMemoryOutStream.cpp',
        'TestDeferredTestReporter.cpp',
        'TestXmlTestReporter.cpp',
        'TestCurrentTest.cpp'
        ]
    bld.program( features = 'test',
                 target = 'TestUnitTest++',
                 source = ['src/tests/'+x for x in source],
                 inst_to = None,
                 use = 'UnitTest++' )
