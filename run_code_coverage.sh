#!/bin/bash

# Initial files and directories
test_app_path=build/tests/smileyfinder_gtest
unit_test_result_output=build/report/tests/smileyfinder_gtest.xml
test_report_directory_path=report/ccov

# Generated files
temp_cov_info=${test_report_directory_path}/cov.info
temp_cov_baseline=${test_report_directory_path}/cov_baseline.info
generated_report_file=${test_report_directory_path}/report.txt
generated_html_directory=${test_report_directory_path}/html

# Colors
readonly CYAN='\033[1;36m'
readonly NC='\033[0m' # No Color

function print() {
    echo -e "$CYAN$1$NC"
}

function build_application() {
    print "Building Application.."
    cd build
    cmake -DENABLE_COVERAGE_BUILD=ON ..
    make
    cd ..
}

function build_test() {
    print "Building Test.."
    cd build
    cmake -DENABLE_UT_BUILD=ON -DENABLE_COVERAGE_BUILD=ON ..
    make
    cd ..
}

function run_tests() {
    print "Running $test_app_path.."
    $test_app_path --gtest_output=xml:$unit_test_result_output
}

function delete_old_generated_files() {
    print "Deleting old files.."
    rm -f ${temp_cov_baseline}
    rm -f ${temp_cov_info}
    rm -f ${generated_report_file}
    rm -rf ${generated_html_directory}
    lcov --zerocounters --directory .
}

function run_test_coverage_baseline() {
    print "Running coverage baseline.."
    # Run initial/baseline lcov
    lcov --no-external --capture --initial --directory . --output-file ${temp_cov_baseline}
}

function run_test_coverage() {
    print "Collect all code coverage data.."
    # Collect all code coverage data
    lcov --no-external -c -d . -o ${temp_cov_info}
    
    # Combine lcov tracefiles
    lcov --add-tracefile ${temp_cov_baseline} --add-tracefile ${temp_cov_info} --output-file ${temp_cov_info}

    print "Removing main.cpp codes.."
    # Do not collect coverage data for generated files
    lcov -r ${temp_cov_info} --rc lcov_branch_coverage=1 /**tools/** -o ${temp_cov_info}
    lcov -r ${temp_cov_info} --rc lcov_branch_coverage=1 /**src/main.cpp -o ${temp_cov_info}

    print "Removing tests codes.."
    # Do not collect coverage data for tests files
    lcov -r ${temp_cov_info} --rc lcov_branch_coverage=1 /**tests/** -o ${temp_cov_info}

    print "Generating HTML Reports.."
    # Genetate html report
    genhtml ${temp_cov_info} -o ${generated_html_directory}
    
    print "Generating terminal and text Report.."
    # Generate a textual report, display it and save it in report.txt file
    lcov -q -l ${temp_cov_info} | tee ${generated_report_file}
}

delete_old_generated_files || exit

build_application   || exit

run_test_coverage_baseline || exit

build_test || exit

run_tests || exit

run_test_coverage || exit

echo
echo "Text report is saved in File     : " $PWD/${generated_report_file}
echo "HTML report is saved in directory: " $PWD/${generated_html_directory}