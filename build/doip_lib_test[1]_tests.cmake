add_test([=[ConvertTest.ShortToByteArray]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=ConvertTest.ShortToByteArray]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ConvertTest.ShortToByteArray]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[ConvertTest.IntegerToByteArray]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=ConvertTest.IntegerToByteArray]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ConvertTest.IntegerToByteArray]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[ConvertTest.ByteArrayToShort]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=ConvertTest.ByteArrayToShort]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ConvertTest.ByteArrayToShort]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[ConvertTest.ByteArrayToInteger]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=ConvertTest.ByteArrayToInteger]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[ConvertTest.ByteArrayToInteger]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[MessageTest.ValidPayloadTypeExtraction]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=MessageTest.ValidPayloadTypeExtraction]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MessageTest.ValidPayloadTypeExtraction]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[MessageTest.InvalidPayloadTypeExtraction]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=MessageTest.InvalidPayloadTypeExtraction]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MessageTest.InvalidPayloadTypeExtraction]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[GenericNackTest.NackCodeProperty]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=GenericNackTest.NackCodeProperty]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GenericNackTest.NackCodeProperty]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[GenericNackTest.Serialization]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=GenericNackTest.Serialization]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GenericNackTest.Serialization]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[GenericNackTest.ValidDeserialization]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=GenericNackTest.ValidDeserialization]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GenericNackTest.ValidDeserialization]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[GenericNackTest.InvalidTypeDeserialization]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=GenericNackTest.InvalidTypeDeserialization]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GenericNackTest.InvalidTypeDeserialization]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[GenericNackTest.InvalidLengthDeserialization]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=GenericNackTest.InvalidLengthDeserialization]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GenericNackTest.InvalidLengthDeserialization]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[VehicleIdRequestTest.ValidDeserialization]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=VehicleIdRequestTest.ValidDeserialization]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[VehicleIdRequestTest.ValidDeserialization]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[VehicleIdRequestTest.InvalidDeserialization]=]  /home/runner/work/DoIP-Lib/DoIP-Lib/build/doip_lib_test [==[--gtest_filter=VehicleIdRequestTest.InvalidDeserialization]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[VehicleIdRequestTest.InvalidDeserialization]=]  PROPERTIES WORKING_DIRECTORY /home/runner/work/DoIP-Lib/DoIP-Lib/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  doip_lib_test_TESTS ConvertTest.ShortToByteArray ConvertTest.IntegerToByteArray ConvertTest.ByteArrayToShort ConvertTest.ByteArrayToInteger MessageTest.ValidPayloadTypeExtraction MessageTest.InvalidPayloadTypeExtraction GenericNackTest.NackCodeProperty GenericNackTest.Serialization GenericNackTest.ValidDeserialization GenericNackTest.InvalidTypeDeserialization GenericNackTest.InvalidLengthDeserialization VehicleIdRequestTest.ValidDeserialization VehicleIdRequestTest.InvalidDeserialization)