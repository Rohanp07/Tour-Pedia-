import React, { useEffect, useState } from 'react'
import { MDBCard, MDBCardBody, MDBInput, MDBCardFooter, MDBValidation, MDBBtn, MDBIcon, MDBSpinner, MDBValidationItem } from 'mdb-react-ui-kit';
import { Link, useNavigate } from 'react-router-dom';

import { useDispatch, useSelector } from 'react-redux';
import { toast } from 'react-toastify';
import { register } from '../redux/features/authSlice';

const initialState = {
  firstName: '',
  lastName: '',
  email: '',
  password: '',
  confirmPassword: '',
}

const Register = () => {
  const [formValue, setFormValue] = useState(initialState);
  const { firstName, lastName, email, password, confirmPassword } = formValue;

  //loading states,error  and stuff
  const { loading, error } = useSelector((state) => ({ ...state.auth }));


  //redux
  const dispatch = useDispatch();

  //navigator
  const navigate = useNavigate();

  useEffect(() => {
    error && toast.error(error);


  }, [error]);

  const handleSubmit = (e) => {
    e.preventDefault();

    if (password !== confirmPassword) {
      return toast.error("Passwords do not match");

    }

    //if we have email and password both then only call login action 
    if (email && password && firstName && lastName && confirmPassword) {

      dispatch(register({ formValue, navigate, toast }));
    }


  }

  const onInputChange = (e) => {
    let { name, value } = e.target;
    setFormValue({ ...formValue, [name]: value });


  }

  return (
    <div style={{ margin: "auto", padding: "15px", maxWidth: "450px", alignContent: "center", marginTop: "120px" }}>
      <MDBCard>
        <MDBIcon fas icon="user-circle" className="fa-2x" />
        <h5>sign Up</h5>
        <MDBCardBody>
          <MDBValidation onSubmit={handleSubmit} noValidate className='row g-3'>

            <div className='col-md-6'>
              <MDBValidationItem feedback="Please provide  FirstName" invalid>
                <MDBInput
                  label="First Name"
                  type="text"
                  value={firstName}
                  name="firstName"
                  onChange={onInputChange}
                  required
                />
              </MDBValidationItem>

            </div>

            <div className='col-md-6'>
              <MDBValidationItem feedback="Please provide  lastName" invalid>
                <MDBInput
                  label="Last Name"
                  type="text"
                  value={lastName}
                  name="lastName"
                  onChange={onInputChange}
                  required
                />
              </MDBValidationItem>

            </div>

            <div className='col-md-12'>
              <MDBValidationItem feedback="Please provide  email" invalid>
                <MDBInput
                  label="Email"
                  type="email"
                  value={email}
                  name="email"
                  onChange={onInputChange}
                  required
                />
              </MDBValidationItem>

            </div>
            <div className='col-md-12'>
              <MDBValidationItem feedback="Please provide  password" invalid >
                <MDBInput
                  label="Password"
                  type="password"
                  value={password}
                  name="password"
                  onChange={onInputChange}
                  required

                />
              </MDBValidationItem>
            </div>
            <div className='col-md-12'>
              <MDBValidationItem feedback="Please comfirm  password" invalid >
                <MDBInput
                  label="Confirm Password"
                  type="password"
                  value={confirmPassword}
                  name="confirmPassword"
                  onChange={onInputChange}
                  required

                />
              </MDBValidationItem>
            </div>

            <div className='col-md-12'>

              <MDBBtn style={{ width: "100%" }} className="mt-2">
                {loading && (
                  <MDBSpinner
                    size="sm"
                    role="status"
                    tag='span'
                    className='me-2'
                  />
                )}
                Register
              </MDBBtn>
            </div>

          </MDBValidation>
        </MDBCardBody>
        <MDBCardFooter>
          <Link to="/login">
            <p>Already have  an account ? sign In</p>

          </Link>
        </MDBCardFooter>
      </MDBCard>

    </div>
  )
}

export default Register;