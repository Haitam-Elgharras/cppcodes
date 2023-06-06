
            {
                float a = stof(operandStack.pop());

                cout << "top result" << a << endl;
                string op = opratorStack.pop();
                cout << "top result" << op << endl;

                float b = stof(operandStack.pop());
                cout << "top result" << b << endl;
                float result = evalOp(a, b, op);
                cout << "hello from result =>" << result << endl;
                operandStack.push(to_string(result));
            }