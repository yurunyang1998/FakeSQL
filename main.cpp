
#include <iostream>
#include "vector"

#include "B-tree-initial.hpp"
#include "file_read_write_system.h"
#include <random>
#include <bson.h>
#include <bson-types.h>
#include "bson_.h"
using namespace utils;

//static bool
//my_visit_before (const bson_iter_t *iter, const char *key, void *data)
//{
//    int *count = (int *) data;
//
//    (*count)++;
//
//    /* returning true stops further iteration of the document */
//
//    return false;
//}
//
//static void
//count_fields (bson_t *doc)
//{
//    bson_visitor_t visitor = {0};
//    bson_iter_t iter;
//    int count = 0;
//
//    visitor.visit_before = my_visit_before;
//
//    if (bson_iter_init (&iter, doc)) {
//        bson_iter_visit_all (&iter, &visitor, &count);
//    }
//
//    printf ("Found %d fields.\n", count);
//}


int main() {

    basic_read_write    bs("./test.txt");


    bson_::bson_couple b;
    string attr("attr");
    string value("value");
    b.insert_UTF8_value("111", "222");
    //b.insert_int32_value("1111", 683);

    bson_::bson_couple b2;
    string attr2("attrattr");
    string value2("valuevlaue");
    b2.insert_UTF8_value("333","444");
    //b2.insert_int32_value("int32",453);

    bson_::bson_couple b3;
    b3.insert_UTF8_value("555","666");

    bs.write_bsonCouple(&b3,b3.getBsonBuf());
    bs.write_bsonCouple(&b2,b2.getBsonBuf());
    bs.write_bsonCouple(&b,b.getBsonBuf());
//    bson_writer_t *writer;
//    uint8_t *buf = NULL;
//    size_t buflen = 0;
//    bson_t *doc = bson_new();
//
//    writer = bson_writer_new (&buf, &buflen, 0, bson_realloc_ctx, NULL);
//    int i;
//
//    for (i = 0; i < 10; i++) {
//        //bson_append_int32(doc,"i",-1,i);
//        bson_writer_begin (writer, &doc);
//
//        bson_append_utf8(doc,"a",-1,"b",-1);
//        //cout<<bson_writer_get_length(writer)<<endl;
//        bson_writer_end(writer);
//
//    }
////    bson_writer_end (writer);
//
//    //count_fields(doc);
//
//    cout<<bson_writer_get_length(writer)<<endl;
//
//
//    bson_reader_t *reader = bson_reader_new_from_data(buf,120);
//    const bson_t *b;
//    char *str;
//    while ((b = bson_reader_read (reader, NULL))) {
//        str = bson_as_canonical_extended_json (b, NULL);
//        fprintf (stdout, "%s\n", str);
//        bson_free (str);
//    }
}
////    bson_t b=BSON_INITIALIZER;
////    //char a[] ="ad";
////    bson_append_utf8 (&b, "key", -1,"123", -1);
////    bson_append_utf8 (&b, "key23", -1, "value2", -1);
////    //cout<<b['key'];
////    int avf;
////
////    //bson_t *b;
////    bson_iter_t iter;
////
////    //if ((b = bson_new_from_data (my_data, my_data_len)))
////    {
////        const bson_value_t *value;
////        if (bson_iter_init (&iter, &b)) {
////            while (bson_iter_next (&iter)) {
////                printf ("Found element key: \"%s\"\n", bson_iter_key (&iter));
////                value  = bson_iter_value(&iter);
////                cout<<value->value.v_utf8.str;
////            }
////        }
////        bson_destroy (&b);
////    }
//
//
//
////    Manager<int, int> manager(-2147483648);
////
////    for(int i=0;i<100000;i++) {
////        if (i % 1000 == 0)
////            cout << i << endl;
////        manager.insert_data(i, i);
////    }
////
//
////
////    for (int i=0;i<50;i++)
////        manager.data_search(i);
////    basic_read_write testfile("../test.tfrecord");
////    int a;
////    testfile.insert_value("jtsghrz");
//
//
//
//
//
//
//
//
//
//// reply:
//// ???????????????
//// 这玩意有点儿太大了吧....
//// 要不换个小的?
//
////reply: 2018.8.4
////没有找到小一号的
//
//
///*
//
//                                                    MMMMMMM
//                                                    .MMMMMMMMH
//                                                      .MMMMMMMMMMM
//                                                        MMMMMMMMMMMM'
//                                                         'MMMMMMMMMMMMM
//                                                           MMMMMMMMMMMMMMM
//                                                            MMMMMMMMMMMMMMMM.
//                                                             .MMMMMMMMMMMMMMMMH          H
//                                                              MMMMMMMMMMMMMMMMMM          M
//                                                               :MMMMMMMMMMMMMMMMMM         M
//                                                               :MMMMMMMMMMMMMMMMMMMM        M
//                                                                .MMMMMMMMMMMMMMMMMMMMM       M
//                                                                 MMMMMMMMMMMMMMMMMMMMMM:      M
//                                                                 MMMMMMMMMMMMMMMMMMMMMMMM      M
//                                                                  HMMMMMMMMMMMMMMMMMMMMMMM     HM
//                                                                  MMMMMMMMMMMMMMMMMMMMMMMMM     .I
//                                                                   MMMMMMMMMMMMMMMMMMMMMMMMM     M
//                                                                   'MMMMMMMMMMMMMMMMMMMMMMMMM'    M
//                                                                    MMMMMMMMMMMMMMMMMMMMMMMMMM.    M
//                                                                    MMMMMMMMMMMMMMMMMMMMMMMMMMMH   MM
//                                                                    :MMMMMMMMMMMMMMMMMMMMMMMMMMMM   M
//                                                                     MMMMMMMMMMMMMMMMMMMMMMMMMMMM.   M
//                                                                     MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   M
//                ..MMMMMMMMMMMMMMMMMMMMMMMMMMM:M.                     :MMMMMMMMMMMMMMMMMMMMMMMMMMMMM:  H
//      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMH                MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   M
//   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM   M
//    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM         MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  M
//       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM. '.
//          MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM' M
//            HMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.M
//               MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'M
//                IMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:M
//                  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                    .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'
//                      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'
//                        MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                         MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                           .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                                            H'                    :
//                            HMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                                       MH                    :MM
//                             :MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                                   MM.                  MMMMM
//                               MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                                M:                MMMMMMMM.
//                                MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                           :M             'MMMMMMMMMMMM
//                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                        MM           MMMMMMMMMMMMMMM
//                                  .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                     MM       MMMMMMMMMMMMMMMMMMM
//                                   .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.                 MM    MMMMMMMMMMMMMMMMMMMMMM
//                  MMMMMM             HMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM               MM  MMMMMMMMMMMMMMMMMMMMMMMM
//                        MMMM.         MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM            MMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                            MMM'       MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'        MMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                              MMMM      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                MMMM    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:
//                                  MMMM   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                    MMM  HMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMH
//               MMMMMMMMM:            .MM  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                 MMMMMMMMMMMMMMMMMMH   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                     MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'MMMMMMMMMMMMMMMMMM.H'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                        MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMMMM'MMMMMMMMMMMMMMMMMMO''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'
//                           MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMMMM''MMMMMMMMMMMMMMMMM.''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'
//                             MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM: MMMMMM.'' MMMMMMMMMMMMMMMMM'''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.
//                               MMMMMMMMMMMMMMMMMMMMMMMMMMMMM' MMMMMM''':MMMMMMMMMMMMMM'M'''MMMMMMMMMMMMMMMM'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                 .MMMMMMMMMMMMMMMMMMMMMMMMMMMM MMMMM''''MMMMMMMMMMMMMM'''''MMMMMMMMMMMMMMM'''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                   IMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'''''MMMMMMMMMMMMM.'''''MMMMMMMMMMMMM''''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.
//                                     MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'''''MMMMMMMMMMMMM''''''MMMMMMMMMMMMM''M'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                       MMMMMMMMMMMMMMMMMMMMMMMMMM'MMM'''''MMMMMMMMMMMM''M''''MMMMMMMMMMM'''M'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM           .MMMMMMMMMMMMMMMM'
//                                        MMMMMMMMMMMMMMMMMM'MMMMMMM'MMM'''''MMMMMMMMMMMH'M''''MMMMMMMMMMM'''M'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'    MMMMMM
//                                         'MMMMMMMMMMM'''MM'''MMMMM''.M.'''''MMMMMMMMMMM'M'''''MMMMMMMMM'''':'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMH''
//                                           .MMMMMMMMM'MM''M''''MMMM ''M''''''MMMMMMMMMM'M'''''MMMMMMMMM'''''M.MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'.:
//                                             MMMMMMMM.'''MM''''''MMMM''M'''''''MMMMMMMM'' '''''MMMMMMMMM''''M'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'
//                                              MMMMMMM.''''MM'''M'''MM''''''''''''MMMMMMM'M'''MMMMMMMMMM:''''M'MMMMMMMMMMMM'''''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:M'
//                                               MMMMMM  '.M'M'''M''''MM''''''''''''MMMMMM'M'MMMMMMMMMM''''''''M'MMMMMMMMMM''''''''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                                MMMMM'M'M''M'''M'''''MMM''''''''''''MMMM'MMMMMMMMMMM'''''''''M'M MM''MMM'''MM'::''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                      .MMM'      MMMM:''M''''''M'''''MMMM''''''''''''MMMMMMMMMMMMMMMM''''''''''M'MM''MM'''M''''''''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                    'MMMMMMMMMMMMMMMMM'''M.MM''M'''''MMMMM''''''''''''MMMMMMMMMMMM''M''''''''''''MM''''''MM'''''M''MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                          MMMMMMMMMMMM''HMM'M'''M''''MMMMMMM'''''''.MMMMMMMMMMMMM'''M.'''''''''''MM'''''MM''M''''.'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                            'MMMMMMMMMM''MMMM''''M''''MMMMMMM''''MMMMMMM'''''M.''''''M'''''''''''MM''''M'M'''M'''M'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                               MMMMMMMM 'MMMM'''' M''''MM'MM .'''MMMMH'''''''''''''''''''''''''''M'''''M MM:'''''M'MMMMMMMMMMMMMMMMMMMMMMMMMMM:'
//                                                 MMMMMMM''H'M''''''M.''''''':''''M:M'''''''''''''''''''''''''''''''''''MM'''''M''M'MMMMMMMMMMMMMMMMMMMMMMMM
//                                                    MMMMM''MM'''''''''''''''''''''''M''''''''''''''''''''''''''''''''''MMHM'''M':'MMMMMMMMMMMMMMMMMMMMMH
//                                                      MMMMM'M'''''''''''''''''''''''HMMM'''''''''''''''''''''''''''''''M''M'''M'''MMMMMMMMMMMMMMMMM:
//                                                        MMMMM''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''.''M'''MMMMMMMMMMMMMM
//                                                           M'''''''''':MM''''''''''''''''''''''''''''''''''''''''''''''''''M''M''MMMMMMMMMMMM
//                                                           M'''''''''''M'''''''''''''''''''''''''''''''''''''''''''''''''''''M''MMMMMMMMMM
//                                                          M''''''''''''''''''''''''''''''''''''''''''''''''''''''''MMM'''M'''''MMMMMMMM
//                                                           M'''''''''''''''''''''''''''''''''''''''''''''''''''''''HM'.M''''''MMMMMMMMMMMMMMMMMMMMMMMM
//                                                            M''''''''''''''''''''''''''''''''''''''''''''''''''H'''MM:''''''MMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                                             HM''''''''''''''''''''''''''''''''''''''''''''''OMM:'''''''''MMMMMMMMMMMMMMMMMMM'
//                                                               M:'''''''''HMMMM''''''''''''''''''''''''''''''MMMM.'''''MMMMMMMMMMMMM M
//                                                                .M''''''MMO::::M''''''''''''''''''''''''''''MMMMMMMMMMMMMMMMMM.
//                                                                  MM''''MMMHIHMM''''''''''''''''''''''''''MMMMMMMMMMMMMMM
//                                                                   MM'''''''''''''''''''''''''''''''''''MMMMMMMMMMMMMMMMMM:
//                                                                     M''''''''''''''''''''''''''''''MMMMMMMMMMMMMMMMMMMMM
//                                                                      M ''''''''''''''''''''''MMMMM'''MMMMM
//                                                                       MM''''''''''''''.MMMMM'''''''''MMM
//                                                                        MMM''''''MMMMMM''''''''''''''''MM
//                                                                        M'MMMMMMM''''''''''''''''''''''MM
//                                                                        H'''''''''''''''''''''''''''''''M
//                                                                       :''''''''''''''''''''''''''''''''M
//                                                                  '    M'''''''''''''''''''''''''''''''':M
//                                                                 MM:::MM'''''''''''''''''''''''''''''''''MMM       MMMMH    H'MMMMMM:HM
//                                                                MH::MMM''''''''''''''''''''''''''''''''''''''MMMM'MH::::::::::::::::::::M.
//                                                         MMMMMHMH::M:MM'''''''''''''''''''''''''''''''''''''''''MM:::::::::::::::IMM':MM::M
//                                                     MMM::::::M::HM':M''''''''''''''''''''''''''''''''''''''''.MH::::::::::::::MM'''''''':MM
//                                                MMMH:::::::::M::MM'''''''''''''''''''''''''''''''''''''''''''MM::::::::::::::M''''''''''''''':M
//                                            HMMM:::::::::::MM::::M'''''''''''''''''''''''''':MHMMMMMMMMMM''.MM:::::::::::::MI'''''''''''''''''''MM
//                                           M::::::::::::::MM:::::MMM'''''''''''''''''''HMMM'''''''''''''''MM::::::::::::::M'''''''''''''''''''''''MM
//                                            M:::::::::::::M:::::::MMMM:''''''''''''''MM'''''''''''''''''MM:::::::::::::::MM'''''''''''''''''''''''''MM
//                                            M::::::::::::::::::::::M'''M'''''''M'''M''''''''''''''''''MM:::::::::::::::::M'''''''''''''''''''''''''''MM
//                                           MH:::H::::::::::::::::::M''''''''''..'::'''''''''''''''':MM:::::::::::::::::::M''''''''''''''''''''''''''''M
//                                          M:':::M:::::::::::::::::::M''''''MMM:''''''''''''''''''MMH:::::::::::::::::::::M''''''''''''''''''''''''''''M
//                                         M'''M::M::::H:::::::::::::::O''''''''''''''''''''''MMMM:::::::::::::::::::::::::M''''''''''''''''''''''''''''M
//                                        '.'''M:M:::::M:::::::::::::::H''''''''''''''''''''MM:::::::::::::::::::::::::::::M''''''''''''''''''''''''''''M
//                                       'M''''.HM::::::M:::H:::::::::::H'''M'''''''''''MMM::::::::::::::::::::::::::::::::M'''''.''''''''''''''''''''''M
//                                       M''''''M::::::::::::M:::::::::::M''M''''''''MMH:::::::::::::::::::::::::::::::::::MM'''''''''''''''''''''''''''M'
//                                      M'''''''M::::::::M::::H::::::::::::'H''''''MM::::::::::::::::::::::::::::::::::::::MM'''H:''''''''''''''''''''''MHM
//                                      ''''''''M:::::::::M:::::::::::::::MM ''''M:::::::::::::::::::::::::::H:::::::::::::OM'''M'''''''''''''''''''''''M'HM
//                                     'M''''''H:::::::::::MM::::M:::::::::M''M::::::::::::::::::::::::::::.::::::::::::::::M''MM'''''''''''''''''''''''''''M
//                                      M''''''M:::::::::::MMM:::::::::::::HM::::::::::::::::::::::::::::M::::::::::::::::::MM.MM'''''''''''''''''''''''''''MM
//                                      M''''''M::::::::::::MMH::::::::::::::::::::::::::::::::::::::::MH:::::::::::::::::::M:MMM''''''''''''''''''''''''''''H'
//                                      H:'''''H:::::::::::::MMM::::::::::::::::::::::::::::::::::::::M:::::::::::::::::::::::::M'''''''''''''''''''''''''''''M
//                                      M'''''M:::::::::::::::HMM:::::::::::::::::::::::::::::::::::M::::::::::::::M::::::::::::MO'''''''''''''''''''''''''''''M
//                                      M'''''M::::::::::::::::::M:::::::::::::::::::::::::::::::HMM:::::::::::::::::M::::::::::MM''''''''''''''''''''''''''''':M
//                                      M'''''M::::::::::::::::::::::::::::::::::::::::::::HMH::::::::::::::::::::M::::M::::::::MM''''''''''''''''''''''''''''''.'
//                                     M.''''.::::::::::::::::::::::::::::::::::::::::HM::::::::::::::::::::::::::::M:::MH:::::::M'''''''''''''''''''''''''''''''M
//                                     M'''''M::::::::::::::::::::::::::::::::::::MM::::::::::::::::::::::::::::::::::M:::MM:::::M'''''''''''''''''''''''''''''''':
//                                    .M'''''M::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::M::::MM:MM''''''''''''''''''''''''''''''''M
//                                    M''''''M::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::M:::::HM'''''''''''''''''''''''''''''''''M
//                                   'M'''''.H:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MM::IM''''''''''''''''''''''''''''''''M
//                                   M''''''M:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::HMMMM''''''''''''''''''''''''''''''''MM
//                                   M''''''M:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MMM M''''''''''''''''''''''''''''''''MM
//                                   M'''''.H::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MM   :M''''''''''''''''''''''''''''''''M
//                                  M.'''''M::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::HM     M''''''''''''''''''''''''''''''''M
//                                  M''''''M::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::M      'M'''''''''''''''''''''''''''''''.'
//                                  M''''''M:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::M::      .M'''''''''''''''''''''''''''''''M
//                                 M'''''''MMI::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::H::M         M'''''''''''''''''''''''''''''M.
//                                 M''''''''''MM:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::M:::M          'M'M''''''''''''''''''''''''''M.
//                                 M.'''''''''''MM::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::M::::M            M:M''''''''''''''''''''''''''MM
//                                  M'''''''''''''MM:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::M             HM''''''''''''''''''''''''''''MM
//                                  M.''''''''''''''M:::::::::::::::::MMMMM::MM::::::::::::::::::::::::::::::::::::::::::::MM               M.''''''''''''''''''''''''''''MM
//                                  'M''''''''''''''''MM::::::::::::OMM '  M   MM:HMMMMMMMMMMI:::::::::::::::::::::::::::MM                 MM'''''''''''''''''''''''''''''OM
//                                  M'''''''''''''''''MMMMMMMMM'     M MM M   M .M                   '::'H:HMMMMM:::::MM.                   ::''''''''''''''''''''''''''''''M
//                                  :''''''''''''''''''MM           M  H  '  MM   M :'...H                        'MMH                      M:'''''''''''''''''''''''''''''''M
//                                 M''''''''''''''''''MMM      HMM: M    M  MMMM     MMM.'                          M                       MM'''''''''''''''''''''''''''''''M:
//                                'M''''''''''''''''''''MMMMO      MM  M   .M MMH   M                                M                      MM'''''''''''''''''''''''''''''''.M
//                                M:'''''''''''''''''''MM:           HH    M:  MM   M'                              M                       .M''''''''''''''''''''''''''''''''M
//                                M''''''''''''''''''''MM       MMM  M  M   :   M:  I:::::::::MOHMMMM'             M                         MM'''''''''''''''''''''''''''''''M'
//                                M''''''''''''''''''''':MHMO:::::  ':HMM:H:M   .M   M:::::::::M::::::::::M::IMMM M                           MM''''''''''''''''''''''''''''''MM
//                                M'''''''''''''''''''''M::::::::M  O  :::::M:   M   M::::::::::M::::::::::M:::::HM                            MM''''''''''''''''''''''''''''':M
//                                M'''''''''''''''''''':M::::::::H  M H::::::M   M   M:::::::::::M:::::::::HM:::::MM                            MM'''''''''''''''''''''''''''''M
//                                M''''''''''''''''''''M::::::::M   M M::::::M   MO  ':::::::::::MM:::::::::M:::::::M                            MM''''''''''''''''''''''''''''MM
//                                M'''''''''''''''''''M:::::::::M  H  M::::::M    M   M:::::::::::M::::::::::H::::::MM                            MM'''''''''''''MMMMMMMMMMMMMMMMMM
//                                HM'''''''''''''''''HM:::::::::   M  M::::::M    M   M::::::::::::M:::::::::M:::::::M                             M'''''''''' MMMMMMMMMMMMMMMMMMMM
//                                 MMMMMMMMMMMMMMMMMMM:::::::::M   M  H::::::M    M   M::::::::::::H:::::::::M:::::::MM                             M''''''HMMMMMMMMMMMMMMMMMMMMMMM
//                                HMMMMMMMMMMMMMMMMMMM:::::::::   M'  M:::::::         M::::::::::::M:::::::::::::::::M                              M''''MMMMMMMMMMMMMMMMMMMMMMMMM
//                                 MMMMMMMMMMMMMMMMMM:::::::::M   M   ::::::::M    .   M:::::::::::::M::::::::::::::::.M                              M'MMMMMMMMMMMMMMMMMMMMMMMMMMM.
//                                 MMMMMMMMMMMMMMMMMMH::::::::M   M  '::::::::M    M   M:::::::::::::H:::::::::::::::::MH                              MMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                'MMMMMMMMMMMMMMMMMM:::::::::M   :  :::::::::M    M    M:::::::::::::::::::::::::::::::M                             MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                MMMMMMMMMMMMMMMMMMM:::::::::    .  M::::::::M    '    M::::::::::::::::::::::::::::::::M                            'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                MMMMMMMMMMMMMMMMMMM::::::::M   M   M::::::::M         M:::::::::::::::::::::::::::::::::'                            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                MMMMMMMMMMMMMMMMMMM::::::::M   M   M::::::::M         M:::::::::::::::::::::::::::::::::M                             MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                MMMMMMMMMMMMMMMMMMM::::::::M   M   M::::::::M          ::::::::::::::::::::::::::::::::::M                            MMMMMMMMMMMMMMMMMMMMMMMMMMMMMH
//                                MMMMMMMMMMMMMMMMMMM::::::::    H   M::::::::M          M:::::::::::::::::::::::::::::::::M                             MMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                               :MMMMMMMMMMMMMMMMMMM:::::::H    '   H::::::::M          M::::::::::::::::::::::::::::::::::M                             MMMMMMMMMMMMMM:''''''''''M
//                                MMMMMMMMMMMMMMMMMMM:::::::M        :::::::::M          M:::::::::::::::::::::::::::::::::::M                             MMMMMM.''''''''''''''''''.
//                                 MMM:''''''''MMMMMM:::::::M   M   .:::::::::M'          O:::::::::::::::::::::M:::::::::::::M                             M'''''''''''''''''''''''M
//                                 M'''''''''''''''MM:::::::M       M:::::::::M           M:::::::::::::::::::::M:::::::::::::M                            M''''''''''''''''''''''''M
//                                 M''M''''''''''''MM:::::::        M:::::::::M           H:::::::::::::::::::::H:::::::::::::M.                         MM'''''''''''''''''''''''''.M
//                                 M''M''''''''''''M::::::::        ::::::::::M.          M:::::::::::::::::::::H::::::::::::H:::                      MM'''''''''''''''''M''''''''''M
//                                M.''M''''''''''''M:::::::M        .:::::::::M.          H::::::::::::::::::::::::::::::::::H::M                      M'''''''''''''''''''M'''''''''M
//                                M'''M'''''''''''M::::::::M         :::::::::M.           ::::::::::::::::::::M:::::::::::::M::MM                     :'''''''''''''''''''M''''''''':
//                                M'''M''''''''''MH::::::::M        ':::::::::M'           M:::::::::::::::::::M:::::::::::::M::M:M                     M'''.M''''''''M'''''''''''''''M
//                                :''M''''''''''MM:::::::::'        '::::::::::M           M:::::::::::::::::::M:::::::::::::I:::::M                    M''''M''''''''M'''''M'''''''''M
//                               M'''M'''''''''MM::::::::::          ::::::::::M           'H:::::::::::::::::M::::::::::::::::::::HM                   'M''''M'''''''M'''''M''''':'''M
//                               M''''''''''''MM''H:::::::M         :::::::::::M            M:::::::::::::::::M:::::::::::::::::::::HM                   M'MMM:'''''''M'''''M'''''''''M
//                               M''O'''''''IM'' :M:::::::M         :::::::::::M            M:::::::::::::::::M::::::::::::::::::::::M:                  M''''''''''''M''''''''''''MMM
//                              M'''' M''''' ''''MM:::::::M          M:::::::::M          MMH::::::::::::::::M:::::M::::::::::::::::::M                  MM'''M''''''''M'''''M''''M
//                              MM''MM'M''''M  M'MM:::::::M          H:::::::::M       .M::::::::::::::::::::M::::M::::::::::::::::::::M                    M'M:'''''''M''''MMMMMM
//                               MM'':''''M'.''M:'M:::::::M          ::::::::::M      ::::::::::::::::::::::H:::::H:::::::::::::::::::::M                    M'M''''''''''''M
//                                .M'''''':M''H'''M:::::::M MM:::::MMM:::::::::M    M:::::::::::::::::::::::M::::M::::::::::::::::::::::OM                   :M'''''''MMMMMM
//                                 HM'''MM'M''M'''M:::::::M::::::::::::::::::::M   M:::::::::::::::::::::::HM:::M::::::::::::::::::::::::MM                    :''''MM
//                                   MMMMMM''M MMMM::::::::::::::::::::::::::::M MM::::::::::::::::::::::::M::::M:::::::::::::::::::::::::MM                   'MMM
//                                                M::::::::::::::::::::::::::::MHH:::::::::::::::::::::::::M:::M:::::::::::::::::::::::::::M.
//                                               'M::::::::::::::::::::::::::::MMMM:::::::::::::::::::::::M:::M:::::::::::::::::::::::::::::M
//                                               HM::::::::::::::::::::::::::::::MM:::::::::::::::::::::::M::OH::::::::::::::::::::::::::::::M
//                                               MH:::::::::::::::::::::::::::::::M::::::::::::::::::::::M:::M:::::::::::::::::::::::::::::::M
//                                               M::::::::::::::::::::::::::::::::M:::::::::::::::::::::OM::M::::::::::::::::::::::::::::::::M
//                                               M::::::::::::::::::::::::::::::::MM::::::::::::::::::::M::MH::::::::::::::::::::::::::::::::M
//                                               M::::::::::::::::::::::::::::::::OM::::::::::::::::::::M::M:::::::::::::::::::::::::::::::::MH'
//                                               M::::M::::::::::::::::::::::::::::MM:::::::::::::::::::::M::::::::::::::::::::::::::::::::::M::M
//                                               M::::M::::::::::::::::::::::::::::MM::::::::::::::::::::M::::::::::::::::::::::::::::::::::MM:::M
//                                               M::::MH::::::::::::::::::::::::::::MH:::::::::::::::::::M::::::::::::::::::::::::::::::::::M::::I
//                                               M::::HM::::::::::::::::::::::::::::MM::::::::::::::::::::::::::::::::::::::::::::::::::::::M::::.
//                                              'M:::::M::::::::::::::::::::::::::::M:::::::::::::::::::::::::::::::::::::::::::::::::::::::M:::H
//                                              MM:::::M:::::::::::::::::::::::::::::M::::::::::::::::::::::::::::::::::::::::::::::::::::::M:::OM
//                                              MM:::::MH::::::::::::::::::::::::::::HH::::::::::::::::::::::::::::::::::::::::::::::::::::MM:::MMM
//                                              MH::::::M::::::::::::::::::::::::::::MM::::::::::::::::::::::::::::::::::::::::::::::::::::M::::M:MM
//                                              MH::::::M::::::::::::::::::::::::::::IM::::::::::::::::::::::::::::::::::::::::::::::::::::M::::M::M
//                                              MH:::::::M:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::M::::M:::M:
//                                              MH:::::::M::::::::::::::::::::::::::::M:::::::::::::::::::::::::::::::::::::::::::::::::::MM:::MM:::IM'
//                                             'M::::::::HH:::::::::::::::::::::::::::.M::::::::::::::::::::::::::::::::::::::::::::::::::MH:::MM::::HMM
//                                             IM:::::::::M:::::::::::::::::::::::::::HM::::::::::::::::::::::::::::::::::::::::::::::::::M::::M::::::MM:
//                                             MM:::::::::H:::::::::::::::::::::::::::HM::::::::::::::::::::::::::::::::::::::::::::::::::M::::M::::::::M'
//                                             MM::::::::::M:::::::::::::::::::::::::::M:::::::::::::::::::::::::::::::::::::::::::::::::HM::::M::::::::MM
//                                             MM::::::::::MM::::::::::::::::::::::::::M:::::::::::::::::::::::::::::::::::::::::::::::::MH::::M::::::::.MM
//                                             M::::::::::::M::::::::::::::::::::::::::MM::::::::::::::::::::::::::::::::::::::::::::::::M::::IM:::M:::::HMM
//                                             M:::::::::::::M::::::::::::::::::::::::::M::::::::::::::::::::::::::::::::::::::::::::::::M:::::M:::M:::::::M.
//                                            'M:::::::::::::MM:::::::::::::::::::::::::M:::::::::::::::::::::::::::::::::::::::::::::::::::::M::::MI::::::MM
//                                            MH::::::::::::::MO::::::::::::::::::::::::M:::::::::::::::::::::::::::::::::::::::::::::::::::::M:::::M:::::::M
//                                            MM:::::::::::::::M::::::::::::::::::::::::H::::::::::::::::::::::::::::::::::::::::::::::::::::HM:::::M:::::::MM
//                                            M::::::::::::::::MM:::::::::::::::::::::::.::::::::::::::::::::::::::::::::::::::::::::::::::::M::::::M::::::::M
//                                            M:::::::::::::::::M:::::::::::::::::::::::HM::::::::::::::::::::::::::::::::::::::::::::::::::HM::::::M:::::::::M
//                                            M::::::::::::::::::MH::::::::::::::::::::::M::::::::::::::::::::::::::::::::::::::::::::::::::M:::::::M:::::::::M.
//                                           :M::::::::::::::::::::::::::::::::::::::::::M:::::::::::::::::::::::::::::::::::::::::::::::::MM:::::::M::::::::::M
//                                           'M::::::::::::::::::::::::::::::::::::::::::M:::::::::::::::::::::::::::::::::::::::::::::::::M::::::::M::::::::::M
//                                            MH:::::::::::::::::::::::::::::::::::::::::M::::::::::::::::::::::::::::::::::::::::::::::::MM:::::::::::::::::::M
//                                             MM::::::::::::::::::::::::::::::::::::::::HM::::::::::::::::::::::::::::::::::::::::::::::HM:::::::::H:::::::::M
//                                              MM::::::::::::::::::::::::::::::::::::::::MM:::::::::::::::::::::::::::::::::::::::::::::MM::::::::M::::::::::M
//                                               HM::::::::::::::::::::::::::::::::::::::::HMH::::::::::::::::::::::::::::::::::::::::::MM:::::::::M::::::::::M
//                                                .MH:::::::::::::::::::::::::::::::::::::::HMM::::::::::::::::::::::::::::::::::::::::HMM:::::::::M:::::::::M
//                                                  MM::::::::::::::::::::::::::::::::::::::MMMMMM:::::::::::::::::::::::::::::::::::::MH::::::::::M:::::::::M
//                                                   MM::::::::::::::::::::::::::::::::::::MM:::MMMH::::::::::::::::::::::::::::::::::::::::::::::MM::::::::::
//                                                    MMH:::::::::::::::::::::::::::::::::MM:::::M: MM::::::::::::::::::::::::::::::::::::::::::::M:::::::::M
//                                                    MMMM::::::::::::::::::::::::::::::MMI::::::M  MMMM:::::::::::::::::::::::::::::::::::::::::M::::::::::M
//                                                   MM:MMM:::::::::::::::::::::::::::MMM::::::::M  'M::MH:::::::::::::::::::::::::::::::::::::::M::::::::::H
//                                                   HM:::MMM:::::::::::::::::::::::IMM::::::::::M   M::::MM::::::::::::::::::::::::::::::::::::MM:::::::::M
//                                                   IM::::MMM:::::::::::::::::::::MM::::::MM:::M     ::::::MM::::::::::::::::::::::::::::::::::MO:::::::::M
//                                                   MM::::::MMM:::::::::::::::::MM:::::::M:M:::M     M:::::::MM:::::::::::::::::::::::::::::::MM:::::::::M
//                                                   MM::::::MOMM::::::::::::::MM::::::::M::::::M     M:::::::::HM:::::::::::::::::::::::::::::MM:::::::::M
//                                                   MM::::::M::IMM:::::::::MMM::::::::HM:::::::M     .:::::::::::MM::::M:::::::::::::::::::::HM:::::::::M
//                                                   MM::::::M::::MM::::::M:::::::::::MM::::::::M     I:::::::::::::MM::::M:::::::::::::::::::M::::::::::M
//                                                   MH::::::M:::::MM::::::::::::::::MM:::::::::M      O::::::::::::::M::::MM::::::::::::::::HM:::::::::M
//                                                   MM::::::MH:::::M:::::::::::::::MI::::::::OMH      'M::::::::::::::MH::::MM::::::::::::::M:::::::::HM
//                                                   MM:::::::M:::::H::::::::::::::M::::::::HMH           MM::::::::::::H::::::M:::::::::::::::::::::::M'
//                                                    MM::::::M::::::::::::::::::HM::::::::M'               MM:::::::::::H::::::MM:::::::::::::::::::::M
//                                                     MM:::::H::::::::::::::::::M::::::MM                     MI:::::::::::::::::MM::::::::::::::::::MM
//                                                      MM:::::M::::::::::::::::M:::::MM                         MM::::::::::::::::MMM::::::::::::::::M
//                                                        MH::::M::::::::::::::M::HMMMM                            MMM:::::::::::::::MMM:::::::::::::MM'
//                                                         MMMMMMMMMMMMMMMMMMMMMMMMMMMM                              'MM::::::::::::::MMMMM:::::::::MMM
//                                                          MMMMMMMMMMMMMMMMMMMMMMMMMMM                                 MM:::::::::::::MMMM:::MMMMMMMMM
//                                                           MMMMMMMMMMMMMMMMMMMMMMM.M                                   :MMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                                            M''''''''''''''''''''''MM                                   MMMMMMMMMMMMMMMMMMMMMMMMMMM'M
//                                                            M'''''''''''''''''''''''M                                    MMMMMMMMMMMMMMMMMMMMMMM:'''''
//                                                          O''''''''''''''''''''''''''                                     MMMMMMMMMM.I.''''''''''''''M
//                                                          H''M'''''''''''''''''''''''M                                     M''''''''''''''''''''''''''M
//                                                         MM'''' :MM'''''''''''''''''''M                                   'M''.MH:''''''''''''''''''''M
//                                                      MM'''''''''''''''''''''''''''''HM                                   .M.''''''''''''''''''''''''''M
//                                                   MM:''''''''''''''''''''''''''''''MMMM                                  MM'''''''''''''''''''''''''''M
//                                                MMMMMMM'''''''''''''''''''''''''' MMMMMM                                 'M'''''''IHMMMMMMMM '''''''''''M
//                                             MMMMMMMMMMM:'''''''''''''''''''''HMMMMMMMMM                                 MH'':MMMMMMMMMMMMMMMMM'''''''''M
//                                          'MMMMMMMMMMMMMMMH''''''''''HMMMMMMMMMMMMMMMMMMM                               OM'MMMMMMMMMMMMMMMMMMMMMH'''''''MM
//                                        MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                               M'MMMMMMMMMMMMMMMMMMMMMMMM '''''MM
//                                     'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                               MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:
//                                     MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                              MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                               MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:                                     'MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                     .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM                                               HMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMH
//                                            'MMMMMMMMMM:                                                             MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//                                                                                                                      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
// */
