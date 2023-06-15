#!/usr/bin/env bash

project_name='prog3_PC2_teo3_v2023_1'
source_code='
        parallel_product.h
        split_range.h
  '
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}