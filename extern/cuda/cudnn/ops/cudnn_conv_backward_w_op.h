// ***************************************************************
// Copyright (c) 2020 Jittor. Authors: 
//     Dun Liang <randonlang@gmail.com>
//     Guowei Yang <471184555@qq.com>
// All Rights Reserved.
// This file is subject to the terms and conditions defined in
// file 'LICENSE.txt', which is part of this source code package.
// ***************************************************************
#pragma once
#include "op.h"

namespace jittor {

struct CudnnConvBackwardWOp : Op {
    Var* x, * dy, * dw;
    int kernel_size, stride, padding, dilation;
    string xformat, wformat, yformat;

    CudnnConvBackwardWOp(Var* x, Var* y, int kernel_size, int stride, int padding, int dilation, string xformat="abcd", string wformat="oihw", string yformat="abcd");
    
    const char* name() const override { return "cudnn_conv_backward_w"; }
    void infer_shape() override;
    DECLARE_jit_run;
};

} // jittor