/* Copyright 2020 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#include <nncase/codegen/k210/module_builder.h>
//#include <nncase/codegen/stackvm/op_writer.h>
#include <nncase/ir/ops/batch_to_space.h>
#include <nncase/ir/ops/binary.h>
#include <nncase/ir/ops/broadcast.h>
#include <nncase/ir/ops/conv2d.h>
#include <nncase/ir/ops/reduce.h>
#include <nncase/ir/ops/transpose.h>
#include <nncase/ir/ops/unary.h>
#include <nncase/ir/placeholders.h>
#include <nncase/schedule/scheduler.h>

namespace nncase::codegen::k210
{
//class k210_op_builder : public op_builder
//{
//public:
//    using op_builder::op_builder;
//
//    void stshape(uint8_t rshape, const ir::shape_t &shape);
//    void staxis(uint8_t rshape, const ir::axis_t &axis);
//    void stpaddings(uint8_t rpaddings, std::span<padding const> paddings);
//    void lea_buffer(const schedule::buffer_allocation &alloc);
//    void ldpadding(const padding &pad);
//};

class k210_module_builder : public module_builder
{
public:
    k210_module_builder(std::string_view module_name, const schedule::module_schedule_result &sched);

    module_type_t module_type() const noexcept override;

protected:
    section_writer &text_writer();

    void emit(ir::node &node) override;

private:
    //#define DEFINE_OP(op_) void emit(ir::op_ &op, stackvm_op_builder &builder);
    //#include "ops.def"
    //#undef DEFINE_OP
};
}