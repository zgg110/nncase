﻿using System;
using System.Collections.Generic;
using System.Text;
using NnCase.Evaluation;
using NnCase.Targets.CPU;
using NnCase.Targets.K210.Evaluation.Operators;
using NnCase.Targets.K210.Transforms;
using NnCase.Transforms;

namespace NnCase.Targets.K210
{
    public class K210Target : CPUTarget
    {
        protected override void AddOptimize2Transforms(List<Transform> transforms)
        {
            transforms.AddRange(new Transform[]
            {
                new KPUFakeConv2DTransform()
            });

            base.AddOptimize2Transforms(transforms);
        }

        public override void RegisterEvaluators(EvaluatorRegistry registry)
        {
            K210Evaulators.Register(registry);
            base.RegisterEvaluators(registry);
        }
    }
}